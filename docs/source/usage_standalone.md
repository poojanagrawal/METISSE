# Using METISSE as a standalone code 

## Running METISSE 

*makefile* in folder *make* contains all necessary instructions to compile METISSE in the standalone mode. 

To compile the package open a command line shell and inside the METISSE folder execute:

```bash
[~/METISSE]$ ./mk
```

You will now see an exceutable named `metisse` which was not there before. 

The code does not needs to re-compiled unless you make changes inside the source `src` directory. 

Let us say we want to evolve a 1 M$_\odot$ star at metallicity, Z = 0.02 upto 12 Gyr and write output to a SSE-style file.
So `main.input` will look like this:

```
&SSE_input_controls

initial_Z = 0.02

max_age = 1.2d4   

number_of_tracks = 1
min_mass = 1

write_track_to_file = .true.   
/

```

Next we should supply path to the input tracks through `metisse.input`. 

```
&METISSE_input_controls


tracks_dir = '/Users/poojan/stellar_tracks/MESA/METISSE_INPUT_FILES/Hydrogen'
            
tracks_dir_he = '/Users/poojan/stellar_tracks/MESA/METISSE_INPUT_FILES/Helium'

verbose = .true.

/

```
Note that we have also set `verbose` to true so that we can see details of the input tracks on the screen. 
If verbose is False, then these details are written `tracks.log.txt` file. 

To run METISSE simply type `./metisse` on the command line:

``` bash
[~/METISSE]$ ./metisse
 Input Z is :  0.020000
 Reading naked helium star tracks
 Reading input files from: /Users/poojan/stellar_tracks/MESA/METISSE_INPUT_FILES/Helium/./He_z02/eeps/
 Found:           50  tracks
 Minimum initial mass    0.5
 Maximum initial mass   49.8
 Reading main (hydrogen star) tracks
 Reading input files from: /Users/poojan/stellar_tracks/MESA/METISSE_INPUT_FILES/Hydrogen/./H_z02/eeps/
 Found:          100  tracks
 Minimum initial mass    0.1
 Maximum initial mass  293.3
 count        1  input mass =   1.000
     Time        0.0    Phase         MS     Mass   1.000
     Time     9470.1    Phase         HG     Mass   1.000
     Time    11192.3    Phase        FGB     Mass   0.999
     Time    12000.0    Phase        FGB     Mass   0.999
 -------------------------------------------------------------------------
 Reached the end of the program
```

Check the *output* directory for output data files.


