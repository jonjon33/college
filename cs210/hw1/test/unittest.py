import subprocess

filename = "samp1.ccx"
filelist = [ "complex.cci" , "complex.ccx" , "date.cci" , "date.ccx" , "hello_world.ccx" , "list.cci" , "list.ccx" , "natural.cci" , "natural.ccx" , "samp1.ccx" , "samp2.ccx" , "samp3.ccx" , "widget.cci" , "widget.ccx" ]

for filename in filelist:
    args = ( "../bin/hw1" , "ccxSamples/"+filename )
    proc = subprocess.Popen(args,stdout=subprocess.PIPE)
    proc.wait()
    output = proc.stdout.read()
    outfile = open("temp",'w')
    outfile.write(output)
    outfile.close()


    args = ("diff","-s","temp","ccxSamples/"+filename+".lexer.out")
    proc = subprocess.Popen(args,stdout=subprocess.PIPE)
    proc.wait()
    output = proc.stdout.read()
    print output

args = ("rm","temp")
proc = subprocess.Popen(args)
proc.wait()
