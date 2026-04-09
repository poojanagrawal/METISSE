subroutine abundances(kw, mass, mt, tm, tn, tscls, lums, GB, zpars, dtm, id)

    use track_support
    use interp_support

! need to know mass lost the system
! so by each star (winds+binary loss- binary accn)

! mass loss
!take initial model (corresponding to m0)


!find nearest zone m(0-3) is closest to m0-dm
!interpolate in abundances to get the right abundance values at at m0-m
! calculate abundace lost for each species
! mfrac3*zone3+ mfrac2*zone2+....
! mfrac3 is dm/m3-m2

! mass accren
!find nearest zone m(0-3) is closest to m0 the mass
! dilute abundance of the outermost zone containing

end subroutine abundances