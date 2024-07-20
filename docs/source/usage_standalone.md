# Using METISSE as a standalone code 

## Input Files 

In the standalone mode, inputs to METISSE are provided using the Fortran namelists `SSE_input_controls` contained in the *main.input* and `METISSE_input_controls` contained in the *metisse.input*. 

`SSE_input_controls` contains input parameters describing the initial conditions of the star/stellar populations. This namelist is only read in METISSE's standalone mode. When METISSE is used with other codes, the input parameters from the overlying code are utilized.

### EVOLUTION CONTROLS
| Variable name | Description |
|-----------------|-----------------|
|read_mass_from_file | There are two ways stellar mass values can be supplied to METISSE: 1. `read_mass_from_file = .true.` Provide input masses in a text file (one mass value in a line) and specify the location of that file in `input_mass_file`. Use `number_of_tracks` to tell how many mass values are to be used|
|input_mass_file ||
| number_of_tracks |  |
| max_mass| 2. `read_mass_from_file = .false.` Use `min_mass` to specify the lower limit, `max_mass` for the upper limit and `number_of_tracks` to be evolved uniformly distributed in mass between the two limits. To evolve just one star, specify `number_of_tracks = 1` and input mass value in `min_mass`. Ignore max_mass.|
| min_mass | |
| initial_Z | Initial metallicity |
| max_age | Maximum age in Megayears |


```
! EVOLUTION CONTROLS
read_mass_from_file = .false.      
input_mass_file = ''
number_of_tracks = 0
max_mass = -1.0
min_mass = -1.0
initial_Z = -1.0
max_age = -1.0   
```

    
### REMNANT CONTROLS
| Variable name | Description |
|-----------------|-----------------|
| WD_mass_scheme | For white dwarfs, two prescriptions are available for calculating luminosity: (1) "Mestel" - p. 85 of [Shapiro S. L., Teukolsky S. A., 1983](https://ui.adsabs.harvard.edu/abs/1983bhwd.book.....S/abstract) (2) "Modified_mestel" - [Hurley J. R., Shara M. M., 2003, ApJ, 589, 179](https://iopscience.iop.org/article/10.1086/374637) | Use_initial_final_mass_relation | If true, use the initial final mass relation from [add citation]()] for white dwarfs    
| BHNS_mass_scheme |  The type and mass of the NS/BH can  be  calculated  from  one  of  the  following  prescriptions: (1) "original_SSE" - [Default SSE]() (2) "Belczynski2002" - [Belczynski et al. 2002, ApJ, 572, 407](https://iopscience.iop.org/article/10.1086/340304) (3) "Belczynski2008" - [Belczynski et al. 2008, ApJS, 174, 223](https://iopscience.iop.org/article/10.1086/521026) (4) "Eldridge_Tout2004" -  [Eldridge J. J., Tout C. A., 2004, MNRAS, 353, 87](https://ui.adsabs.harvard.edu/abs/2004MNRAS.353...87E/abstract)|
| max_NS_mass | Maximum neutron star mass, suggested 1.8 for BHNS_mass_scheme="original_SSE", 3.0 otherwise|
| allow_electron_capture | Allow electron capture supernovae |     


```
! REMNANT CONTROLS 
WD_mass_scheme = 'Modified_mestel'
BHNS_mass_scheme = 'Belczynski2008'
Max_NS_mass = 3.d0
```
### TIMESTEP CONTROLS
Similar to SSE, METISSE determines timesteps as the fractions of the time spent in a phase
| Variable name | Description |
|-----------------|-----------------|
| pts_1 | 95% of MS, HeMS, default is 
| pts_2 | last 5% of MS, cHeBurn, HeHG, HeGB
| pts_3 |  HG, RGB, EAGB, TPAGB

```
! TIMESTEP CONTROLS
pts_1 = 0.05
pts_2 = 0.01
pts_3 = 0.02
```

### OUTPUT CONTROLS
| Variable name | Description |
|-----------------|-----------------|
| write_track_to_file | Generate an SSE-style output file (file ending in .dat) at the END of the evolution. Default is false|

```
! OUTPUT CONTROLS
write_track_to_file = .false.
```
`METISSE_input_controls` contains input parameters specific to METISSE. 

### TRACK CONTROLS
| Variable name | Description |
|-----------------|-----------------|
tracks_dir | METISSE looks for files(s) ending with *metallicity.in* in the paths provided through 'tracks_dir'. A metallicity file contains details about the set of input tracks for a given metallicity, such as the path to the folder, their metallicity value and other information/metadata. For a grid of stellar tracks, containing sets of stellar tracks with different metallicities, the above paths can contain a list of metallicity files, and METISSE will select the based on `Z_accuracy_limit`.|
| tracks_dir_he | While 'tracks_dir' is for providing the location of the metallicity file(s) for hydrogen stars, 'tracks_dir_he' is for providing the location of the metallicity file(s) for the naked helium/stripped stars. If an empty string is passed then SSE fitting formulae or naked helium stars are used.|
| Z_accuracy_limit | METISSE checks for the following condition to find a match in metallicity `(abs(Z_input-Z_required)/MIN(Z_input,Z_required)) > Z_accuracy_limit`, where Z_input is the metallicity value of the tracks (contained in the metallicity file) and Z_required is the value we want to use. Default is 1d-2|


```
! TRACK CONTROLS
tracks_dir = ''
tracks_dir_he = ''
Z_accuracy_limit = 1d-2
```

### OUTPUT CONTROLS
| Variable name | Description |
|-----------------|-----------------|
| verbose | If true, 'verbose' prints useful details when reading the files. Default is false| 
| write_eep_file | Generate MIST style output file at EVERY step of mass interpolation useful for debugging and single star evolution calculations with implicit mass loss. Default is false|
| write_error_to_file | If true error messages are written to a file (usually fort.99) otherwise they are printed on screen (does NOT apply to errors during reading input files). Default is true|

```
! OUTPUT CONTROLS
verbose = .false. 
write_eep_file = .false.		
write_error_to_file = .true.
```
    
### MISCELLANEOUS CONTROLS
| Variable name | Description |
|-----------------|-----------------|
| mass_accuracy_limit | Skip interpolation in mass if there is already an input track with initial_mass within the 'mass_accuracy_limit' Default is 1d-4|
| construct_wd_track | 'construct_wd_track' is used (for low-mass stars) to artificially construct the track between Thermally-Pulsating AGB phase or tip of the AGB to the white dwarf cooling track. It is useful if input tracks do not contain this phase but can be used otherwise too. Default is true| 

```
! MISCELLANEOUS CONTROLS
mass_accuracy_limit = 1d-4
construct_wd_track = .true.
```
    
Both `SSE_input_controls` and `METISSE_input_controls` are Fortran namelists, so comments (anything after the exclamation mark symbol!) and whitespaces can be used freely. Characters are also case-insensitive. 
**Although make sure to leave a blank line at the end of the file (after the `/` symbol)**

For the most up-to-date variable names and their default values refer to [main_defaults.inc](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/main_defaults.inc)   and [metisse_defaults.inc](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/metisse_defaults.inc). 
**Never modify any file inside the defaults folder**.


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
 Reached the end of the program
```

Check the *output* directory for output data files.


