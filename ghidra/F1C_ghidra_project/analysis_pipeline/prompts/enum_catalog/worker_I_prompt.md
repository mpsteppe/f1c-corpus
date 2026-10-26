# WORKER I — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker I of 20, items 2649–2979.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_I.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

2649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401910__FUN_00401910.c
2650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404820__FUN_00404820.c
2651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404f70__FUN_00404f70.c
2652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405900__sub_405900.c
2653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406659__sub_406659.c
2654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407810__FUN_00407810.c
2655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408250__FUN_00408250.c
2656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409770__FUN_00409770.c
2657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b450__FUN_0040b450.c
2658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c650__FUN_0040c650.c
2659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d340__FUN_0040d340.c
2660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1d0__FUN_0040e1d0.c
2661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ef70__FUN_0040ef70.c
2662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b20__FUN_00410b20.c
2663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411ab0__FUN_00411ab0.c
2664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004141f0__FUN_004141f0.c
2665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415230__FUN_00415230.c
2666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418940__FUN_00418940.c
2667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00419500__FUN_00419500.c
2668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b200__FUN_0041b200.c
2669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ef40__FUN_0041ef40.c
2670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421380__FUN_00421380.c
2671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a90__FUN_00421a90.c
2672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424010__FUN_00424010.c
2673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426cf0__FUN_00426cf0.c
2674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ad50__FUN_0042ad50.c
2675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bc80__FUN_0042bc80.c
2676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ddd0__FUN_0042ddd0.c
2677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00430750__FUN_00430750.c
2678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432650__FUN_00432650.c
2679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004331a0__FUN_004331a0.c
2680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434460__FUN_00434460.c
2681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00436230__FUN_00436230.c
2682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043aee0__FUN_0043aee0.c
2683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ebd0__FUN_0043ebd0.c
2684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00442c90__FUN_00442c90.c
2685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447b10__FUN_00447b10.c
2686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448de0__FUN_00448de0.c
2687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449eb7__FUN_00449eb7.c
2688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b910__FUN_0044b910.c
2689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c7d0__FUN_0044c7d0.c
2690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb14__sub_44CB14.c
2691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cda0__FUN_0044cda0.c
2692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d010__FUN_0044d010.c
2693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d370__FUN_0044d370.c
2694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d730__FUN_0044d730.c
2695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044daf0__FUN_0044daf0.c
2696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044deb0__FUN_0044deb0.c
2697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e270__FUN_0044e270.c
2698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e630__FUN_0044e630.c
2699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e9f0__FUN_0044e9f0.c
2700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044efe0__FUN_0044efe0.c
2701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f8f0__FUN_0044f8f0.c
2702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004532d0__FUN_004532d0.c
2703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456060__FUN_00456060.c
2704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457b60__FUN_00457b60.c
2705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459990__FUN_00459990.c
2706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b9a0__FUN_0045b9a0.c
2707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf10__FUN_0045bf10.c
2708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c8f0__FUN_0045c8f0.c
2709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e590__FUN_0045e590.c
2710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461440__FUN_00461440.c
2711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461fc0__FUN_00461fc0.c
2712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004628a0__FUN_004628a0.c
2713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463c80__FUN_00463c80.c
2714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004649f0__FUN_004649f0.c
2715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004651c0__FUN_004651c0.c
2716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004662c0__FUN_004662c0.c
2717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00467720__FUN_00467720.c
2718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a480__FUN_0046a480.c
2719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c6f0__FUN_0046c6f0.c
2720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046da20__FUN_0046da20.c
2721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f610__FUN_0046f610.c
2722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004706f0__FUN_004706f0.c
2723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471a00__FUN_00471a00.c
2724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004735b0__sub_4735B0.c
2725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474c70__FUN_00474c70.c
2726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476080__FUN_00476080.c
2727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477280__FUN_00477280.c
2728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478110__FUN_00478110.c
2729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004795e0__FUN_004795e0.c
2730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479a10__FUN_00479a10.c
2731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a260__FUN_0047a260.c
2732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b850__FUN_0047b850.c
2733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c860__sub_47C860.c
2734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f0a0__sub_47F0A0.c
2735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485690__FUN_00485690.c
2736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486240__FUN_00486240.c
2737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486660__FUN_00486660.c
2738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004871f0__sub_4871F0.c
2739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487830__FUN_00487830.c
2740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004889d0__FUN_004889d0.c
2741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489600__FUN_00489600.c
2742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a650__sub_48A650.c
2743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b9c0__FUN_0048b9c0.c
2744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d0d0__FUN_0048d0d0.c
2745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048dff0__FUN_0048dff0.c
2746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ea20__FUN_0048ea20.c
2747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fca0__sub_48FCA0.c
2748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004903f0__FUN_004903f0.c
2749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491330__FUN_00491330.c
2750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491d10__FUN_00491d10.c
2751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494bf0__FUN_00494bf0.c
2752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495140__FUN_00495140.c
2753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b60__FUN_00495b60.c
2754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004972a6__sub_4972A6.c
2755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497d00__FUN_00497d00.c
2756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498880__FUN_00498880.c
2757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498fe0__FUN_00498fe0.c
2758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499690__FUN_00499690.c
2759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499bf0__FUN_00499bf0.c
2760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499f00__FUN_00499f00.c
2761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a520__FUN_0049a520.c
2762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aec0__FUN_0049aec0.c
2763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b950__FUN_0049b950.c
2764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d480__FUN_0049d480.c
2765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e8f0__FUN_0049e8f0.c
2766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f750__FUN_0049f750.c
2767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0cb0__FUN_004a0cb0.c
2768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1830__FUN_004a1830.c
2769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1fd0__FUN_004a1fd0.c
2770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3fe0__FUN_004a3fe0.c
2771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a56b0__FUN_004a56b0.c
2772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6d50__FUN_004a6d50.c
2773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004af220__FUN_004af220.c
2774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1600__FUN_004b1600.c
2775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1c80__sub_4B1C80.c
2776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b25d0__FUN_004b25d0.c
2777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b60__FUN_004b2b60.c
2778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3ce0__FUN_004b3ce0.c
2779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b46b0__FUN_004b46b0.c
2780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b54a0__FUN_004b54a0.c
2781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b69a0__FUN_004b69a0.c
2782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b84f0__FUN_004b84f0.c
2783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9870__FUN_004b9870.c
2784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9f70__FUN_004b9f70.c
2785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004baa50__FUN_004baa50.c
2786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb5a0__FUN_004bb5a0.c
2787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc320__FUN_004bc320.c
2788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdf90__FUN_004bdf90.c
2789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bfa00__FUN_004bfa00.c
2790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c11d0__FUN_004c11d0.c
2791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2850__FUN_004c2850.c
2792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fb0__FUN_004c2fb0.c
2793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4bb0__FUN_004c4bb0.c
2794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6780__FUN_004c6780.c
2795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7b50__FUN_004c7b50.c
2796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c82c0__FUN_004c82c0.c
2797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8dc0__FUN_004c8dc0.c
2798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9960__FUN_004c9960.c
2799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cad30__FUN_004cad30.c
2800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cd6c0__FUN_004cd6c0.c
2801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cfcc0__FUN_004cfcc0.c
2802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1730__FUN_004d1730.c
2803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2e20__FUN_004d2e20.c
2804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5900__FUN_004d5900.c
2805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7960__sub_4D7960.c
2806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7fe0__FUN_004d7fe0.c
2807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d91e0__FUN_004d91e0.c
2808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dae00__FUN_004dae00.c
2809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbab0__FUN_004dbab0.c
2810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc660__FUN_004dc660.c
2811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd030__FUN_004dd030.c
2812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004def70__FUN_004def70.c
2813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0ed0__FUN_004e0ed0.c
2814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2a00__FUN_004e2a00.c
2815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e45b0__FUN_004e45b0.c
2816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e88b0__FUN_004e88b0.c
2817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec020__FUN_004ec020.c
2818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef180__FUN_004ef180.c
2819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0430__FUN_004f0430.c
2820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1c00__FUN_004f1c00.c
2821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6950__FUN_004f6950.c
2822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8280__FUN_004f8280.c
2823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8d10__FUN_004f8d10.c
2824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f30__FUN_004f9f30.c
2825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc870__FUN_004fc870.c
2826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff1d0__FUN_004ff1d0.c
2827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006a4__FUN_005006a4.c
2828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050210e__FUN_0050210e.c
2829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503a70__FUN_00503a70.c
2830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005064bf__FUN_005064bf.c
2831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507ac4__FUN_00507ac4.c
2832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508e67__FUN_00508e67.c
2833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509de6__FUN_00509de6.c
2834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a8f5__FUN_0050a8f5.c
2835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b244__FUN_0050b244.c
2836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b7cb__FUN_0050b7cb.c
2837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2b3__thunk_FUN_0050c2a6.c
2838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ca2d__sub_50CA2D.c
2839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d690__FUN_0050d690.c
2840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050de2c__sub_50DE2C.c
2841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e491__sub_50E491.c
2842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f6f7__FUN_0050f6f7.c
2843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510f89__FUN_00510f89.c
2844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511b5c__FUN_00511b5c.c
2845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005124de__FUN_005124de.c
2846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513cd8__FUN_00513cd8.c
2847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005158e3__FUN_005158e3.c
2848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005161dd__FUN_005161dd.c
2849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516f76__FUN_00516f76.c
2850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f58__FUN_00517f58.c
2851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005199c5__sub_5199C5.c
2852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051b7cd__FUN_0051b7cd.c
2853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c653__FUN_0051c653.c
2854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051db31__FUN_0051db31.c
2855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051eb6e__FUN_0051eb6e.c
2856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f7ce__sub_51F7CE.c
2857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520a7e__sub_520A7E.c
2858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522876__sub_522876.c
2859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00526392__sub_526392.c
2860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052851d__FUN_0052851d.c
2861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052b561__FUN_0052b561.c
2862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e080__FUN_0052e080.c
2863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005317c0__FUN_005317c0.c
2864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005354e0__FUN_005354e0.c
2865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536fd0__FUN_00536fd0.c
2866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539200__sub_539200.c
2867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053aeb0__FUN_0053aeb0.c
2868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bde0__FUN_0053bde0.c
2869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6f0__FUN_0053c6f0.c
2870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d340__FUN_0053d340.c
2871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fed0__FUN_0053fed0.c
2872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541120__FUN_00541120.c
2873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541db0__FUN_00541db0.c
2874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543210__FUN_00543210.c
2875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543fa0__FUN_00543fa0.c
2876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005455f0__FUN_005455f0.c
2877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546250__FUN_00546250.c
2878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005473c0__FUN_005473c0.c
2879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548a30__FUN_00548a30.c
2880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549440__FUN_00549440.c
2881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054ac30__FUN_0054ac30.c
2882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bda0__FUN_0054bda0.c
2883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c410__FUN_0054c410.c
2884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eac0__FUN_0054eac0.c
2885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc10__FUN_0054fc10.c
2886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005503a0__FUN_005503a0.c
2887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551440__FUN_00551440.c
2888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005523e0__FUN_005523e0.c
2889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553700__FUN_00553700.c
2890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554660__FUN_00554660.c
2891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005563e0__FUN_005563e0.c
2892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556900__FUN_00556900.c
2893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005575f0__FUN_005575f0.c
2894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005593c6__sub_5593C6.c
2895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bbf0__FUN_0055bbf0.c
2896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c450__FUN_0055c450.c
2897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d2e0__FUN_0055d2e0.c
2898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ef24__FUN_0055ef24.c
2899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560c00__FUN_00560c00.c
2900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561af8__FUN_00561af8.c
2901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562890__FUN_00562890.c
2902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563a70__FUN_00563a70.c
2903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564530__FUN_00564530.c
2904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564930__FUN_00564930.c
2905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565bb0__FUN_00565bb0.c
2906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005668d0__FUN_005668d0.c
2907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567030__FUN_00567030.c
2908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567a00__FUN_00567a00.c
2909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568540__FUN_00568540.c
2910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569280__FUN_00569280.c
2911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056aa60__FUN_0056aa60.c
2912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d410__FUN_0056d410.c
2913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00575882__FUN_00575882.c
2914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a230__FUN_0057a230.c
2915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a760__FUN_0057a760.c
2916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aa20__FUN_0057aa20.c
2917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b0d0__FUN_0057b0d0.c
2918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b8c0__FUN_0057b8c0.c
2919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057d890__FUN_0057d890.c
2920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ec10__FUN_0057ec10.c
2921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005816b0__sub_5816B0.c
2922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582290__FUN_00582290.c
2923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005830c0__FUN_005830c0.c
2924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583790__FUN_00583790.c
2925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585030__FUN_00585030.c
2926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585cc0__FUN_00585cc0.c
2927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586240__FUN_00586240.c
2928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586d00__FUN_00586d00.c
2929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587200__FUN_00587200.c
2930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587680__FUN_00587680.c
2931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587b96__FUN_00587b96.c
2932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058815f__FUN_0058815f.c
2933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058890e____abnormal_termination.c
2934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058969d__FUN_0058969d.c
2935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d6b__FUN_00589d6b.c
2936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a3b6__FUN_0058a3b6.c
2937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a9da__FUN_0058a9da.c
2938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b4d4__FUN_0058b4d4.c
2939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bef0__FUN_0058bef0.c
2940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c824__FUN_0058c824.c
2941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dcb5__FUN_0058dcb5.c
2942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e41b__FUN_0058e41b.c
2943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fca0__FUN_0058fca0.c
2944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590703__FUN_00590703.c
2945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591d2e__FUN_00591d2e.c
2946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592c46__FUN_00592c46.c
2947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593cfd__FUN_00593cfd.c
2948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059508d__FUN_0059508d.c
2949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595801__FUN_00595801.c
2950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059685f__FUN_0059685f.c
2951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597371__FUN_00597371.c
2952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598502__FUN_00598502.c
2953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598696__inet_ntoa.c
2954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987c1__FUN_005987c1.c
2955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598cdc__uflow.c
2956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005993af__FUN_005993af.c
2957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997ab__FUN_005997ab.c
2958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998db__sub_5998DB.c
2959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599e66__FUN_00599e66.c
2960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a44c__FUN_0059a44c.c
2961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a948__FUN_0059a948.c
2962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae7d__FUN_0059ae7d.c
2963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b650__FUN_0059b650.c
2964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfc3____CxxThrowException_8.c
2965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4c8__Unwind_0059c4c8.c
2966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5e4__Unwind_0059c5e4.c
2967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6ac__Unwind_0059c6ac.c
2968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7fc__Unwind_0059c7fc.c
2969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8f4__Unwind_0059c8f4.c
2970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca5e__Unwind_0059ca5e.c
2971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cbc0__Unwind_0059cbc0.c
2972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd13__Unwind_0059cd13.c
2973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cead__Unwind_0059cead.c
2974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfbe__Unwind_0059cfbe.c
2975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0bd__Unwind_0059d0bd.c
2976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d224__Unwind_0059d224.c
2977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d414__Unwind_0059d414.c
2978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d56c__Unwind_0059d56c.c
2979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059da54__FUN_0059da54.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_I.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
