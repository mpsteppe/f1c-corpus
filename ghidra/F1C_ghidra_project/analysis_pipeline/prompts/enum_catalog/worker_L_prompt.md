# WORKER L — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker L of 20, items 3642–3972.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_L.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

3642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403350__FUN_00403350.c
3643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404890__FUN_00404890.c
3644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405020__sub_405020.c
3645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b00__FUN_00405b00.c
3646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406750__FUN_00406750.c
3647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407be0__FUN_00407be0.c
3648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408290__FUN_00408290.c
3649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409f40__sub_409F40.c
3650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b5c0__sub_40B5C0.c
3651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c7a0__FUN_0040c7a0.c
3652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d410__FUN_0040d410.c
3653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e2b0__FUN_0040e2b0.c
3654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f130__FUN_0040f130.c
3655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b80__FUN_00410b80.c
3656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411db0__FUN_00411db0.c
3657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414370__FUN_00414370.c
3658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004155d0__FUN_004155d0.c
3659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004189f0__FUN_004189f0.c
3660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004199e0__FUN_004199e0.c
3661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b910__FUN_0041b910.c
3662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f070__FUN_0041f070.c
3663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004214a0__FUN_004214a0.c
3664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421af0__FUN_00421af0.c
3665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424750__FUN_00424750.c
3666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429eb0__FUN_00429eb0.c
3667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ae00__FUN_0042ae00.c
3668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042c690__FUN_0042c690.c
3669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e290__FUN_0042e290.c
3670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004313c0__FUN_004313c0.c
3671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432810__FUN_00432810.c
3672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004336d0__FUN_004336d0.c
3673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434860__FUN_00434860.c
3674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00436470__FUN_00436470.c
3675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043bb00__FUN_0043bb00.c
3676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ec80__FUN_0043ec80.c
3677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00443af0__FUN_00443af0.c
3678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447e00__FUN_00447e00.c
3679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448e90__FUN_00448e90.c
3680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a070__FUN_0044a070.c
3681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044bc10__FUN_0044bc10.c
3682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c860__FUN_0044c860.c
3683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb74__sub_44CB74.c
3684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce00__FUN_0044ce00.c
3685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d070__FUN_0044d070.c
3686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d400__FUN_0044d400.c
3687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d7c0__FUN_0044d7c0.c
3688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db80__FUN_0044db80.c
3689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044df40__FUN_0044df40.c
3690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e300__FUN_0044e300.c
3691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e6c0__FUN_0044e6c0.c
3692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea80__FUN_0044ea80.c
3693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f062__sub_44F062.c
3694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fbe0__FUN_0044fbe0.c
3695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00453560__FUN_00453560.c
3696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004560c0__FUN_004560c0.c
3697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457d00__FUN_00457d00.c
3698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459ae0__FUN_00459ae0.c
3699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb00__FUN_0045bb00.c
3700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf90__FUN_0045bf90.c
3701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cd50__FUN_0045cd50.c
3702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5f0__FUN_0045e5f0.c
3703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004614c0__FUN_004614c0.c
3704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462250__FUN_00462250.c
3705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462a10__FUN_00462a10.c
3706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463d10__FUN_00463d10.c
3707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464a60__FUN_00464a60.c
3708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465430__FUN_00465430.c
3709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466350__FUN_00466350.c
3710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00468090__FUN_00468090.c
3711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a530__FUN_0046a530.c
3712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c750__FUN_0046c750.c
3713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046dd30__FUN_0046dd30.c
3714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fd00__FUN_0046fd00.c
3715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470af0__FUN_00470af0.c
3716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472040__FUN_00472040.c
3717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473b90__FUN_00473b90.c
3718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474ff0__FUN_00474ff0.c
3719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004761a0__FUN_004761a0.c
3720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477440__sub_477440.c
3721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004781a0__FUN_004781a0.c
3722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004796c0__FUN_004796c0.c
3723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c00__FUN_00479c00.c
3724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a550__FUN_0047a550.c
3725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bae0__FUN_0047bae0.c
3726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c960__FUN_0047c960.c
3727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f210__FUN_0047f210.c
3728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485720__FUN_00485720.c
3729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004862a0__FUN_004862a0.c
3730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486720__FUN_00486720.c
3731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487220__FUN_00487220.c
3732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004879e0__FUN_004879e0.c
3733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488b30__FUN_00488b30.c
3734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489940__FUN_00489940.c
3735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048aa00__FUN_0048aa00.c
3736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c070__FUN_0048c070.c
3737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d2b0__FUN_0048d2b0.c
3738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e0d0__FUN_0048e0d0.c
3739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048eaa0__FUN_0048eaa0.c
3740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fdb0__FUN_0048fdb0.c
3741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490640__FUN_00490640.c
3742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491600__FUN_00491600.c
3743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e10__FUN_00491e10.c
3744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494c80__FUN_00494c80.c
3745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004952e0__FUN_004952e0.c
3746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496030__FUN_00496030.c
3747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497510__FUN_00497510.c
3748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497ec0__FUN_00497ec0.c
3749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988d0__FUN_004988d0.c
3750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499160__FUN_00499160.c
3751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499870__FUN_00499870.c
3752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499cc0__FUN_00499cc0.c
3753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a150__FUN_0049a150.c
3754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a930__FUN_0049a930.c
3755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afb0__FUN_0049afb0.c
3756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ba50__FUN_0049ba50.c
3757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d700__FUN_0049d700.c
3758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ea10__FUN_0049ea10.c
3759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049feb0__FUN_0049feb0.c
3760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0d30__FUN_004a0d30.c
3761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1a00__FUN_004a1a00.c
3762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2770__FUN_004a2770.c
3763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4050__FUN_004a4050.c
3764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a57a0__FUN_004a57a0.c
3765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6fe0__FUN_004a6fe0.c
3766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b01b0__FUN_004b01b0.c
3767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b17b0__FUN_004b17b0.c
3768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1e20__sub_4B1E20.c
3769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2800__FUN_004b2800.c
3770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2bf0__FUN_004b2bf0.c
3771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3d60__sub_4B3D60.c
3772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b47a0__FUN_004b47a0.c
3773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5760__FUN_004b5760.c
3774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6a10__FUN_004b6a10.c
3775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8790__FUN_004b8790.c
3776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9a00__FUN_004b9a00.c
3777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba140__FUN_004ba140.c
3778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bac20__FUN_004bac20.c
3779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb7a0__FUN_004bb7a0.c
3780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc390__FUN_004bc390.c
3781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be180__FUN_004be180.c
3782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bfd90__FUN_004bfd90.c
3783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c13a0__FUN_004c13a0.c
3784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2990__FUN_004c2990.c
3785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3020__FUN_004c3020.c
3786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4d50__FUN_004c4d50.c
3787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6950__thunk_FUN_00424010.c
3788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c00__FUN_004c7c00.c
3789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c84a0__FUN_004c84a0.c
3790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8f10__FUN_004c8f10.c
3791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9a50__FUN_004c9a50.c
3792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb540__FUN_004cb540.c
3793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cdad0__sub_4CDAD0.c
3794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0060__FUN_004d0060.c
3795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1b50__FUN_004d1b50.c
3796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4580__FUN_004d4580.c
3797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d59b0__FUN_004d59b0.c
3798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7ad0__FUN_004d7ad0.c
3799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8220__FUN_004d8220.c
3800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d93e0__FUN_004d93e0.c
3801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db070__FUN_004db070.c
3802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbc90__FUN_004dbc90.c
3803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcb70__FUN_004dcb70.c
3804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd450__FUN_004dd450.c
3805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004df110__FUN_004df110.c
3806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e17c0__FUN_004e17c0.c
3807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2c70__FUN_004e2c70.c
3808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4930__FUN_004e4930.c
3809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9100__FUN_004e9100.c
3810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec1a0__FUN_004ec1a0.c
3811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef560__FUN_004ef560.c
3812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0f40__FUN_004f0f40.c
3813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1fe0__FUN_004f1fe0.c
3814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6ab0__FUN_004f6ab0.c
3815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f83b0__FUN_004f83b0.c
3816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8ea0__FUN_004f8ea0.c
3817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9fc0__FUN_004f9fc0.c
3818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc9a0__FUN_004fc9a0.c
3819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff670__FUN_004ff670.c
3820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005007ef__FUN_005007ef.c
3821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502a15__FUN_00502a15.c
3822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503e36__FUN_00503e36.c
3823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050653e__FUN_0050653e.c
3824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507dc7__FUN_00507dc7.c
3825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050917d__FUN_0050917d.c
3826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509f70__FUN_00509f70.c
3827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab19__FUN_0050ab19.c
3828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b37d__FUN_0050b37d.c
3829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b813__FUN_0050b813.c
3830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c391__FUN_0050c391.c
3831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cbb0__thunk_FUN_0050cba3.c
3832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d748__FUN_0050d748.c
3833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050df95__thunk_FUN_0050df88.c
3834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e634__sub_50E634.c
3835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f9ab__FUN_0050f9ab.c
3836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005111d3__FUN_005111d3.c
3837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512093__FUN_00512093.c
3838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512850__FUN_00512850.c
3839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513d3d__FUN_00513d3d.c
3840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051593f__FUN_0051593f.c
3841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051641e__FUN_0051641e.c
3842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005172a5__FUN_005172a5.c
3843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00518248__FUN_00518248.c
3844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519d51__FUN_00519d51.c
3845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bc88__FUN_0051bc88.c
3846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c813__FUN_0051c813.c
3847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051df18__FUN_0051df18.c
3848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051eca0__sub_51ECA0.c
3849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051fb1e__sub_51FB1E.c
3850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520e0e__sub_520E0E.c
3851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522a13__sub_522A13.c
3852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005265db__FUN_005265db.c
3853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005285f2__FUN_005285f2.c
3854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8d0__FUN_0052d8d0.c
3855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e2f0__FUN_0052e2f0.c
3856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00532aa0__FUN_00532aa0.c
3857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005355a0__FUN_005355a0.c
3858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537070__FUN_00537070.c
3859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539690__FUN_00539690.c
3860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b110__FUN_0053b110.c
3861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c140__FUN_0053c140.c
3862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c9c0__FUN_0053c9c0.c
3863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d410__FUN_0053d410.c
3864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540150__FUN_00540150.c
3865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541470__FUN_00541470.c
3866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542200__FUN_00542200.c
3867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005432f0__FUN_005432f0.c
3868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544d30__FUN_00544d30.c
3869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005457c0__FUN_005457c0.c
3870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546430__FUN_00546430.c
3871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547420__FUN_00547420.c
3872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548d40__FUN_00548d40.c
3873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a0a0__FUN_0054a0a0.c
3874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b3b0__FUN_0054b3b0.c
3875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bf60__FUN_0054bf60.c
3876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d030__FUN_0054d030.c
3877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eb20__FUN_0054eb20.c
3878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc70__FUN_0054fc70.c
3879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550620__FUN_00550620.c
3880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005514c0__FUN_005514c0.c
3881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005528b0__FUN_005528b0.c
3882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553a20__FUN_00553a20.c
3883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554790__FUN_00554790.c
3884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556510__FUN_00556510.c
3885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005569f0__FUN_005569f0.c
3886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558990__FUN_00558990.c
3887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005596e0__FUN_005596e0.c
3888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bdc0__FUN_0055bdc0.c
3889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c7d0__FUN_0055c7d0.c
3890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d3f0__FUN_0055d3f0.c
3891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055f080__FUN_0055f080.c
3892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560eb0__FUN_00560eb0.c
3893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561e00__FUN_00561e00.c
3894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562c50__FUN_00562c50.c
3895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563e00__FUN_00563e00.c
3896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564600__sub_564600.c
3897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005649d0__FUN_005649d0.c
3898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565dc0__FUN_00565dc0.c
3899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566a70__FUN_00566a70.c
3900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567340__FUN_00567340.c
3901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567af0__thunk_FUN_00567b10.c
3902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568750__FUN_00568750.c
3903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005694e0__FUN_005694e0.c
3904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056bd40__FUN_0056bd40.c
3905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d8f0__FUN_0056d8f0.c
3906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579ccf__FUN_00579ccf.c
3907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a330__FUN_0057a330.c
3908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a820__FUN_0057a820.c
3909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aaf0__FUN_0057aaf0.c
3910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b2e0__FUN_0057b2e0.c
3911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b9a0__FUN_0057b9a0.c
3912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057dbb0__FUN_0057dbb0.c
3913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ef20__FUN_0057ef20.c
3914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005817a0__FUN_005817a0.c
3915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582340__FUN_00582340.c
3916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583210__FUN_00583210.c
3917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583aa0__FUN_00583aa0.c
3918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585220__FUN_00585220.c
3919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585d70__FUN_00585d70.c
3920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586460__FUN_00586460.c
3921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586e50__FUN_00586e50.c
3922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587230__FUN_00587230.c
3923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005876d0__FUN_005876d0.c
3924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587bdc____ftol.c
3925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588212__FUN_00588212.c
3926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058895c__sub_58895C.c
3927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058986e__FUN_0058986e.c
3928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589db0__FUN_00589db0.c
3929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a4e5__FUN_0058a4e5.c
3930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aad9__FUN_0058aad9.c
3931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b75f__FUN_0058b75f.c
3932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c07f____cfltcvt.c
3933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058cc00__FUN_0058cc00.c
3934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd28__FUN_0058dd28.c
3935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058eef7__FUN_0058eef7.c
3936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ff0d__FUN_0058ff0d.c
3937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059086e____fload.c
3938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e57__FUN_00591e57.c
3939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005930e8__FUN_005930e8.c
3940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593dd3__FUN_00593dd3.c
3941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005951be__FUN_005951be.c
3942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595a1f__FUN_00595a1f.c
3943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596a2e__FUN_00596a2e.c
3944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597547__FUN_00597547.c
3945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598630__ntohs.c
3946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986b2__FUN_005986b2.c
3947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987f0__FUN_005987f0.c
3948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598de3__FUN_00598de3.c
3949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599465__FUN_00599465.c
3950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997d5__FUN_005997d5.c
3951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599913__FUN_00599913.c
3952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a01e__FUN_0059a01e.c
3953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a535__FUN_0059a535.c
3954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a9ca__FUN_0059a9ca.c
3955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059af50__FUN_0059af50.c
3956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b9f3__FUN_0059b9f3.c
3957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c156__FUN_0059c156.c
3958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4f0__Unwind_0059c4f0.c
3959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c602__Unwind_0059c602.c
3960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6ca__Unwind_0059c6ca.c
3961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c81a__Unwind_0059c81a.c
3962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c91e__Unwind_0059c91e.c
3963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca8b__sub_59CA8B.c
3964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc00__Unwind_0059cc00.c
3965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd48__Unwind_0059cd48.c
3966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ced7__Unwind_0059ced7.c
3967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfe8__Unwind_0059cfe8.c
3968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0eb__Unwind_0059d0eb.c
3969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d290__Unwind_0059d290.c
3970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d43c__Unwind_0059d43c.c
3971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5a8__Unwind_0059d5a8.c
3972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059daef__FUN_0059daef.c

## TASK
For each .c file:
1. Find switch statements — extract case values and purposes
2. Find comparisons against literal integers (if x == 3, if x < 7, etc.)
3. Find assignments of literal values to globals/struct fields
4. Group related values into enum candidates

## OUTPUT FORMAT

```
=== ENUM DISCOVERIES ===

### EnumName (new or extension of existing)
Source evidence: FUN_XXXXXXXX, FUN_YYYYYYYY
Variable: DAT_XXXXXXXX or param_1+0xNNN

| Value | Meaning | Evidence | Confidence |
|-------|---------|----------|------------|

=== MAGIC NUMBERS ===
| Value | Hex | Type | Used In | Likely Meaning |
|-------|-----|------|---------|---------------|
| 0.017453 | — | float | FUN_X | DEG_TO_RAD |
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_L.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
