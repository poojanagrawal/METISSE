# Using METISSE as a standalone code 

## Input Files 

In the standalone mode, inputs to METISSE are provided using the Fortran namelists `SSE_input_controls` contained in the *main.input* and `METISSE_input_controls` contained in the *metisse.input*. 

`SSE_input_controls` conatains input parameters describing the initial conditions of the star/stellar populations. This namelist is only read in METISSE's standalone mode. When METISSE is used with other codes, the input parameters from the overlying code are utilized.

`METISSE_input_controls` contains input parameters specific to METISSE such as location of the input tracks. 

Both `SSE_input_controls` and `METISSE_input_controls` are Fortran namelists, so comments (anything after the exclamation mark symbol!) and whitespaces can be used freely. Characters are also case-insensitive. 
**Although make sure to leave a blank line at the end of the file (after the `/` symbol)**

For the most up-to-date variable names and their default values refer to [main_defaults.inc](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/main_defaults.inc)   and [metisse_defaults.inc](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/metisse_defaults.inc). 
**Never modify any file inside the defaults folder**.

### 

| Variable name | Description |
|-----------------|-----------------|
| time | Physical time [Myr] |
| age | Age of star [Myr] |
| mass | Current mass of the star [M$_\odot$] |
| core_mass | Mass of dominant core [M$_\odot$] |
| He_core | Mass of helium core [M$_\odot$] |
| CO_core | Mass of carbon-oxygen core [M$_\odot$] |
| log_L | Log of surface luminosity [L$_\odot$] |
| log_Teff | Log of effective temperature [K] |
| log_radius | Log of radius [R$_\odot$] |
| phase | SSE stellar type/phase |



## Output Files

METISSE can produce two types of output files in the standalone mode:

**1. files ending with .dat :**

SSE-like output files, controlled by `write_track_to_file` in SSE_input_controls.
These contain the following stellar parameters until max_age. Time and age at hydrogen ZAMS are assumed to be zero.

| Column Header | Description |
|-----------------|-----------------|
| time | Physical time [Myr] |
| age | Age of star [Myr] |
| mass | Current mass of the star [M$_\odot$] |
| core_mass | Mass of dominant core [M$_\odot$] |
| He_core | Mass of helium core [M$_\odot$] |
| CO_core | Mass of carbon-oxygen core [M$_\odot$] |
| log_L | Log of surface luminosity [L$_\odot$] |
| log_Teff | Log of effective temperature [K] |
| log_radius | Log of radius [R$_\odot$] |
| phase | SSE stellar type/phase |

**2. files ending with .eep :**

For debugging purposes, METISSE can write a mass-interpolated track to an output file with the same columns as input files (plus a phase column) and a MIST-style file structure. 
This output file only contains data from ZAMS to the end of nuclear-burning phases, i.e., it does not contain information about the remnant phase. 
It is controlled by `write_eep_file` in METISSE_input_controls.


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
Note that we have also set `verbose` to True so that we can see details of the input tracks on the screen. 
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
 Reached end of the program
```

Check *output* directory for output data files.


