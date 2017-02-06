#include "TCPIP Stack/TCPIP.h"
#include "p8.h"

// declare AppConfig struct
APP_CONFIG AppConfig;
static unsigned short wOriginalAppConfigChecksum; // checksum of ROM defaults for AppConfig

static void InitAppConfig(void);
static void sysInit(void);
static void ProcessIO(void);
static void CheckIP(Void);
static void delayms(unsigned int);


int main()
{
    sysInit();

    if(USE_LCD)
    {
        lcdinit();
        lcdwrite("CAN Sniffer");
    }

    // init stack-related hardware components
    TickInit();
    MPFSInit();

    // init stack and app related NV variables into AppConfig
    InitAppConfig();

    // init core stack layers and app modules
    StackInit();

    delayms(1000);

    for(;;)
    {
        if(TickGet() - t >= TICK_SECOND/2)
        {
            t = TickGet();
            LATBINV = LEDA;
        }

        StackTask();

        StackApplications();

        ProcessIO();

        CheckIP();
    }
}

void CheckIP()
{
    if(dwLastIP != AppConfig.MyIPAddr.Val)
    {
        dwLastIP = AppConfig.MyIPAddr.Val;

        #if defined(STACK_USE_UART)		// Future feature
            putrsUART((ROM char*)"\r\nNew IP Address: ");
        #endif

// If not vending, show the new IP on terminal and LCD
        if(smVend == SM_IDLE || smVend == SM_DISPLAY_WAIT)
        {
            memcpypgm2ram(LCDText, "WebVend Demo App", 16);
            DisplayIPValue(AppConfig.MyIPAddr);

            #if defined(STACK_USE_UART)
                putrsUART((ROM char*)"\r\n"); // Print to UART
            #endif

            displayTimeout = TickGet() + 2*TICK_SECOND;
            smVend = SM_DISPLAY_WAIT;
        }

        #if defined(STACK_USE_ANNOUNCE)	// Service is optional
            AnnounceIP();
        #endif
}
