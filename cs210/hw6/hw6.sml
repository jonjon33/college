(* Jon Hanson - hans3767
 * May 5, 2017
 * CS 210
 * Homework 6 - SML
 *)

fun hwOutput () = 
    let 
        val name = "hans3767"
        val fname = name ^ ".txt"
        val args = CommandLine.arguments()
        val mylist = [name] @ args @ [name]
        val outs = TextIO.openOut fname
        fun f nil = TextIO.output1 (outs,#"\n")
        | f (h::t) = ( TextIO.output1 (outs,h) ; f t )
        fun g (nil) = nil
        | g (h::t) = ( f (explode h) ; g t )
    in
        g mylist
    end;

hwOutput();

val _ = OS.Process.exit(OS.Process.success)