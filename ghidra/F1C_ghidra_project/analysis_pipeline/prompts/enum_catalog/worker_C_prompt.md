# WORKER C — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker C of 20, items 663–993.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_C.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401080__FUN_00401080.c
664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404250__FUN_00404250.c
665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d50__FUN_00404d50.c
666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004056a0__FUN_004056a0.c
667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406230__FUN_00406230.c
668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407070__FUN_00407070.c
669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408050__FUN_00408050.c
670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004085f0__FUN_004085f0.c
671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ad60__FUN_0040ad60.c
672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c240__FUN_0040c240.c
673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d100__FUN_0040d100.c
674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dcd0__FUN_0040dcd0.c
675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ea30__FUN_0040ea30.c
676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040fdd0__FUN_0040fdd0.c
677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411740__FUN_00411740.c
678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004139c0__FUN_004139c0.c
679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414d70__FUN_00414d70.c
680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004184b0__FUN_004184b0.c
681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418df0__FUN_00418df0.c
682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041aa10__FUN_0041aa10.c
683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041e920__FUN_0041e920.c
684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fe00__FUN_0041fe00.c
685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004219d0__FUN_004219d0.c
686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423a00__FUN_00423a00.c
687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00425920__FUN_00425920.c
688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ac70__FUN_0042ac70.c
689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042b8c0__sub_42B8C0.c
690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dca0__FUN_0042dca0.c
691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ed00__FUN_0042ed00.c
692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c
693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432a60__FUN_00432a60.c
694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434030__FUN_00434030.c
695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435406__sub_435406.c
696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004389b0__FUN_004389b0.c
697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e6a0__FUN_0043e6a0.c
698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441ad0__FUN_00441ad0.c
699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447280__FUN_00447280.c
700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004485c5__sub_4485C5.c
701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004496d0__FUN_004496d0.c
702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044af20__FUN_0044af20.c
703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c6b0__FUN_0044c6b0.c
704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ca40__FUN_0044ca40.c
705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cce0__FUN_0044cce0.c
706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf50__FUN_0044cf50.c
707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d280__FUN_0044d280.c
708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d610__FUN_0044d610.c
709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d9d0__FUN_0044d9d0.c
710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd90__FUN_0044dd90.c
711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e150__FUN_0044e150.c
712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e510__FUN_0044e510.c
713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e8d0__FUN_0044e8d0.c
714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec90__FUN_0044ec90.c
715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f680__FUN_0044f680.c
716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004527e0__FUN_004527e0.c
717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455bd0__FUN_00455bd0.c
718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456fb0__FUN_00456fb0.c
719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459010__FUN_00459010.c
720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b480__FUN_0045b480.c
721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bdf0__FUN_0045bdf0.c
722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c780__FUN_0045c780.c
723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d4e0__FUN_0045d4e0.c
724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460770__FUN_00460770.c
725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461cd0__FUN_00461cd0.c
726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462530__FUN_00462530.c
727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004636f0__FUN_004636f0.c
728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464720__FUN_00464720.c
729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464ef0__FUN_00464ef0.c
730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466140__FUN_00466140.c
731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00467260__FUN_00467260.c
732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469872__sub_469872.c
733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b580__FUN_0046b580.c
734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d610__FUN_0046d610.c
735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ee60__FUN_0046ee60.c
736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470250__FUN_00470250.c
737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004716d0__FUN_004716d0.c
738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472d00__FUN_00472d00.c
739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474510__FUN_00474510.c
740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475cc0__FUN_00475cc0.c
741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476d70__FUN_00476d70.c
742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477ee0__FUN_00477ee0.c
743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478bc0__FUN_00478bc0.c
744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004798e0__FUN_004798e0.c
745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479ed0__FUN_00479ed0.c
746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047aab0__sub_47AAB0.c
747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c0d0__FUN_0047c0d0.c
748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047ee5c__sub_47EE5C.c
749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485570__FUN_00485570.c
750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485df0__FUN_00485df0.c
751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004864c0__FUN_004864c0.c
752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486f30__FUN_00486f30.c
753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487660__FUN_00487660.c
754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004881f0__FUN_004881f0.c
755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489480__FUN_00489480.c
756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489ee0__FUN_00489ee0.c
757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b7e0__FUN_0048b7e0.c
758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ca30__FUN_0048ca30.c
759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d6b0__FUN_0048d6b0.c
760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e6a0__FUN_0048e6a0.c
761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048faf0__FUN_0048faf0.c
762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004901a0__FUN_004901a0.c
763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490ee0__FUN_00490ee0.c
764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491a40__FUN_00491a40.c
765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494620__FUN_00494620.c
766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495060__FUN_00495060.c
767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495970__FUN_00495970.c
768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496e40__FUN_00496e40.c
769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979b0__thunk_FUN_00495b30.c
770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498650__FUN_00498650.c
771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498eb0__FUN_00498eb0.c
772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499580__FUN_00499580.c
773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ae0__FUN_00499ae0.c
774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e70__FUN_00499e70.c
775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2f0__FUN_0049a2f0.c
776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ac20__sub_49AC20.c
777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b670__FUN_0049b670.c
778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d070__FUN_0049d070.c
779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e5b0__FUN_0049e5b0.c
780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f150__FUN_0049f150.c
781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a09a0__FUN_004a09a0.c
782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0fd0__FUN_004a0fd0.c
783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1ea0__sub_4A1EA0.c
784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3560__FUN_004a3560.c
785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4db0__FUN_004a4db0.c
786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5e80__FUN_004a5e80.c
787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004aa1b0__FUN_004aa1b0.c
788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0c00__FUN_004b0c00.c
789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a90__FUN_004b1a90.c
790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b21e0__sub_4B21E0.c
791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2aa0__FUN_004b2aa0.c
792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3af0__FUN_004b3af0.c
793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4450__FUN_004b4450.c
794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b50c0__FUN_004b50c0.c
795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6360__FUN_004b6360.c
796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8090__FUN_004b8090.c
797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b97d0__FUN_004b97d0.c
798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d20__FUN_004b9d20.c
799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba830__FUN_004ba830.c
800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb2e0__FUN_004bb2e0.c
801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc240__FUN_004bc240.c
802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd9b0__FUN_004bd9b0.c
803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf0a0__FUN_004bf0a0.c
804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0a80__FUN_004c0a80.c
805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c22a0__FUN_004c22a0.c
806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2cb0__FUN_004c2cb0.c
807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c45d0__FUN_004c45d0.c
808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5c80__FUN_004c5c80.c
809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7774__FUN_004c7774.c
810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7f28__sub_4C7F28.c
811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8a10__FUN_004c8a10.c
812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c94d0__FUN_004c94d0.c
813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9fb0__FUN_004c9fb0.c
814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc840__FUN_004cc840.c
815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce930__FUN_004ce930.c
816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d10e0__FUN_004d10e0.c
817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d22c0__FUN_004d22c0.c
818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4a20__FUN_004d4a20.c
819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6ae0__FUN_004d6ae0.c
820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e00__FUN_004d7e00.c
821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8950__FUN_004d8950.c
822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004da990__FUN_004da990.c
823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db546__sub_4DB546.c
824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc310__FUN_004dc310.c
825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf30__FUN_004dcf30.c
826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ddf70__FUN_004ddf70.c
827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0d00__FUN_004e0d00.c
828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e23ad__FUN_004e23ad.c
829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3aa0__FUN_004e3aa0.c
830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e5f60__FUN_004e5f60.c
831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea010__FUN_004ea010.c
832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed7b0__FUN_004ed7b0.c
833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efee0__FUN_004efee0.c
834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f18c0__FUN_004f18c0.c
835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f34e0__FUN_004f34e0.c
836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f7000__thunk_FUN_004f83b0.c
837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c50__FUN_004f8c50.c
838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9ad0__FUN_004f9ad0.c
839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fbd70__FUN_004fbd70.c
840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004feaf0__FUN_004feaf0.c
841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005001b0__FUN_005001b0.c
842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00501711__sub_501711.c
843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050368a__FUN_0050368a.c
844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504f5a__FUN_00504f5a.c
845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005076e2__FUN_005076e2.c
846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508867__FUN_00508867.c
847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509a09__FUN_00509a09.c
848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a5cb__FUN_0050a5cb.c
849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050afc6__FUN_0050afc6.c
850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b727__FUN_0050b727.c
851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c134__FUN_0050c134.c
852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c762__sub_50C762.c
853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d4d9__FUN_0050d4d9.c
854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dcb0__FUN_0050dcb0.c
855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e302__FUN_0050e302.c
856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ee0b__FUN_0050ee0b.c
857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051030d__FUN_0051030d.c
858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051177c__FUN_0051177c.c
859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051234d__FUN_0051234d.c
860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b51__FUN_00513b51.c
861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005151af__FUN_005151af.c
862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515ecd__FUN_00515ecd.c
863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005169ac__FUN_005169ac.c
864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517e43__FUN_00517e43.c
865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005196b8__FUN_005196b8.c
866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051aec2__FUN_0051aec2.c
867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c176__FUN_0051c176.c
868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d247__FUN_0051d247.c
869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e6ec__FUN_0051e6ec.c
870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f4c0__sub_51F4C0.c
871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052042e__sub_52042E.c
872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052193c__sub_52193C.c
873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005257c0__FUN_005257c0.c
874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005276c5__FUN_005276c5.c
875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052a0a1__FUN_0052a0a1.c
876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052de40__FUN_0052de40.c
877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e5e0__FUN_0052e5e0.c
878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534f90__FUN_00534f90.c
879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536440__sub_536440.c
880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005386c0__FUN_005386c0.c
881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ac40__FUN_0053ac40.c
882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b4a0__FUN_0053b4a0.c
883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c5b0__FUN_0053c5b0.c
884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d1d0__FUN_0053d1d0.c
885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d970__FUN_0053d970.c
886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540eb0__FUN_00540eb0.c
887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005419d0__FUN_005419d0.c
888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542560__FUN_00542560.c
889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543960__FUN_00543960.c
890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005452b0__FUN_005452b0.c
891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545f40__FUN_00545f40.c
892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547240__FUN_00547240.c
893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005487e0__FUN_005487e0.c
894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005491d0__FUN_005491d0.c
895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a5c0__FUN_0054a5c0.c
896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054ba00__FUN_0054ba00.c
897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c270__FUN_0054c270.c
898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e120__FUN_0054e120.c
899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fa50__FUN_0054fa50.c
900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fe10__FUN_0054fe10.c
901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550ad0__FUN_00550ad0.c
902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551cf0__FUN_00551cf0.c
903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005531f0__FUN_005531f0.c
904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005542f0__FUN_005542f0.c
905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005550c0__FUN_005550c0.c
906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567f5__FUN_005567f5.c
907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005573a0__FUN_005573a0.c
908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559200__FUN_00559200.c
909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559fb0__FUN_00559fb0.c
910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c060__FUN_0055c060.c
911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ceb0__FUN_0055ceb0.c
912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055e320__FUN_0055e320.c
913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005609de__FUN_005609de.c
914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005619af__FUN_005619af.c
915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005622c0__FUN_005622c0.c
916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005631d0__FUN_005631d0.c
917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005642f0__FUN_005642f0.c
918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564810__FUN_00564810.c
919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565140__FUN_00565140.c
920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005665b0__FUN_005665b0.c
921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566df0__FUN_00566df0.c
922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567940__FUN_00567940.c
923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567fb0__FUN_00567fb0.c
924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568e60__thunk_FUN_00568f20.c
925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569de0__FUN_00569de0.c
926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056cf10__FUN_0056cf10.c
927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f090__FUN_0056f090.c
928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a0f0__FUN_0057a0f0.c
929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a660__FUN_0057a660.c
930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a940__FUN_0057a940.c
931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae80__FUN_0057ae80.c
932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b7b0__FUN_0057b7b0.c
933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057c860__FUN_0057c860.c
934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e860__FUN_0057e860.c
935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00580c10__FUN_00580c10.c
936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581d40__FUN_00581d40.c
937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582ce0__FUN_00582ce0.c
938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583660__FUN_00583660.c
939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584dd0__FUN_00584dd0.c
940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585770__FUN_00585770.c
941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585fb0__FUN_00585fb0.c
942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586a10__FUN_00586a10.c
943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005870d0__FUN_005870d0.c
944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005874d0__FUN_005874d0.c
945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587a60__FUN_00587a60.c
946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587f64__FUN_00587f64.c
947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005887b1__FUN_005887b1.c
948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058928f__FUN_0058928f.c
949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589c49__FUN_00589c49.c
950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2cb__FUN_0058a2cb.c
951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a870____aullshr.c
952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058afd8__FUN_0058afd8.c
953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bc4d__FUN_0058bc4d.c
954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c5ac__FUN_0058c5ac.c
955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058da70____trandisp1.c
956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e0b4__FUN_0058e0b4.c
957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f8eb__FUN_0058f8eb.c
958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005904c1__FUN_005904c1.c
959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591bf1__FUN_00591bf1.c
960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592891__FUN_00592891.c
961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005939cf__sub_5939CF.c
962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594bcd__FUN_00594bcd.c
963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059557d__FUN_0059557d.c
964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596100____aullrem.c
965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597093__FUN_00597093.c
966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597fac__FUN_00597fac.c
967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598672__sendto.c
968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059875f__FUN_0059875f.c
969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598bbc__FUN_00598bbc.c
970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059927c__FUN_0059927c.c
971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005996ae__FUN_005996ae.c
972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059987c__FUN_0059987c.c
973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599c58__FUN_00599c58.c
974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a3a9__FUN_0059a3a9.c
975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a81b__FUN_0059a81b.c
976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ad31__FUN_0059ad31.c
977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b2f0__FUN_0059b2f0.c
978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059be0c__FUN_0059be0c.c
979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c478__Unwind_0059c478.c
980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5a8__Unwind_0059c5a8.c
981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c670__Unwind_0059c670.c
982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c790__Unwind_0059c790.c
983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c896__Unwind_0059c896.c
984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9d0__Unwind_0059c9d0.c
985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb60__Unwind_0059cb60.c
986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ccc0__Unwind_0059ccc0.c
987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce60__Unwind_0059ce60.c
988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf53__Unwind_0059cf53.c
989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d07b__Unwind_0059d07b.c
990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1b8__Unwind_0059d1b8.c
991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d358__Unwind_0059d358.c
992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d508__Unwind_0059d508.c
993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d963__FUN_0059d963.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_C.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
