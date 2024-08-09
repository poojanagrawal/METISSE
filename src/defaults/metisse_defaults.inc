! Defaults control for METISSE
! Do NOT make any changes to this file
! Use evolve_metisse.in for input
! Make sure to ADD a new line at the end (after / symbol)in the inlist

!METISSE_input_controls
    
  ! TRACK CONTROLS
    
    ! Absolute path to the folder containing the metallicity files
    ! for the hydrogen stars.
    ! METISSE will stop if tracks_dir is an empty string.
    
    tracks_dir = ''

    ! Absolute path to the folder containing the metallicity files
    ! for the naked helium stars.
    ! If tracks_dir_he is an empty string,
    ! SSE fitting formulae for naked helium stars are used.
    
    tracks_dir_he = ''
    
    
    ! METISSE looks for files(s) ending with *metallicity.in*
    ! in the paths provided through 'tracks_dir' and 'tracks_dir_he'
    ! where 'tracks_dir' is for providing the location of the metallicity file(s)
    ! for hydrogen star and  'tracks_dir_he' is for providing the location
    ! of the metallicity file(s) for the naked helium/stripped stars.
    
    
    ! METISSE checks for a match in metallicity based on the condition:
    !`(abs(Z_input-Z_required)/MIN(Z_input,Z_required)) > Z_accuracy_limit`,
    ! where Z_input is the metallicity value of the tracks (from the metallicity file) and Z_required is the value we want to use.
    
    Z_accuracy_limit = 1d-2

    ! METISSE skips mass-interpolation and uses a neighboring mass track
    ! if the absoulte difference between the initial mass of that track
    ! and the input mass is less than the 'mass_accuracy_limit'

    mass_accuracy_limit = 1d-4

    
  ! MISCELLANEOUS CONTROLS

    ! if true, 'verbose' prints useful details when reading the files

    verbose = .false. 

    ! Generate a MIST-style output file at every step of mass interpolation.
    ! Useful when computing evolution of isolated single stars
    ! with implicit mass loss and for debugging purposes.

    write_eep_file = .false.		

    ! If true error messages are written to a file (usually fort.99)
    ! otherwise they are printed on screen
    ! (does NOT apply to errors during reading input files)
    write_error_to_file = .true.

    ! If .true., artificially construct the HRD (Hertzsprung-Russell diagram)
    ! track between tip of the AGB to the WD cooling track (for low-mass stars).
    ! It is important if input tracks do not contain this phase
    ! but can be used regardless.

    construct_postagb_track = .true.

