# WORKER E — F1C Cross-Validation Audit

You are auditing documented function entries against their actual Ghidra decompilation.
Worker E of 20, items 826–1031.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_E.md

## YOUR FUNCTIONS (206)

826. FUN_004EFBD0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efbd0__FUN_004efbd0.c
827. FUN_00402220
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00402220__FUN_00402220.c
828. FUN_0044C8F0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c8f0__FUN_0044c8f0.c
829. FUN_0044A430
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a430__FUN_0044a430.c
830. FUN_0044E2A0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2a0__FUN_0044e2a0.c
831. FUN_0044D1F0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d1f0__FUN_0044d1f0.c
832. FUN_0044DC40
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc40__FUN_0044dc40.c
833. FUN_0044EBA0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eba0__FUN_0044eba0.c
834. FUN_0044D370
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d370__FUN_0044d370.c
835. FUN_004962C0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004962c0__FUN_004962c0.c
836. FUN_0044F010
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f010__FUN_0044f010.c
837. FUN_0044D550
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d550__FUN_0044d550.c
838. FUN_004584C0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004584c0__FUN_004584c0.c
839. FUN_0044E720
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e720__FUN_0044e720.c
840. FUN_0044D6D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d6d0__FUN_0044d6d0.c
841. FUN_0044C830
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c830__FUN_0044c830.c
842. FUN_0044E6F0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e6f0__FUN_0044e6f0.c
843. FUN_00491AD0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491ad0__FUN_00491ad0.c
844. FUN_004F6AB0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6ab0__FUN_004f6ab0.c
845. FUN_00583700
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583700__FUN_00583700.c
846. FUN_0045E620
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e620__FUN_0045e620.c
847. FUN_00447160
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447160__FUN_00447160.c
848. FUN_00459070
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459070__FUN_00459070.c
849. FUN_00431820
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431820__FUN_00431820.c
850. FUN_004347C0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004347c0__FUN_004347c0.c
851. FUN_004364A0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004364a0__FUN_004364a0.c
852. FUN_0056BD40
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056bd40__FUN_0056bd40.c
853. FUN_0056C540
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c540__FUN_0056c540.c
854. FUN_0043AEE0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043aee0__FUN_0043aee0.c
855. FUN_00434860
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434860__FUN_00434860.c
856. FUN_004CC840
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc840__FUN_004cc840.c
857. FUN_00569410
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569410__FUN_00569410.c
858. FUN_0053B240
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b240__FUN_0053b240.c
859. FUN_004CCE90
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cce90__FUN_004cce90.c
860. FUN_00456170
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456170__FUN_00456170.c
861. FUN_00489920
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489920__FUN_00489920.c
862. FUN_0048E9E0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e9e0__FUN_0048e9e0.c
863. FUN_004981F0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004981f0__FUN_004981f0.c
864. FUN_0047BC30
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bc30__FUN_0047bc30.c
865. FUN_00586800
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586800__FUN_00586800.c
866. FUN_005416A0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005416a0__FUN_005416a0.c
867. FUN_00497100
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497100__FUN_00497100.c
868. FUN_005105BF
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005105bf__FUN_005105bf.c
869. FUN_00507079
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507079__FUN_00507079.c
870. FUN_005147EA
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005147ea__FUN_005147ea.c
871. FUN_00534F90
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534f90__FUN_00534f90.c
872. FUN_00506CCC
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506ccc__FUN_00506ccc.c
873. FUN_00540F00
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540f00__FUN_00540f00.c
874. FUN_00515F0E
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515f0e__FUN_00515f0e.c
875. FUN_0050B399
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b399__FUN_0050b399.c
876. FUN_004CEF30
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cef30__FUN_004cef30.c
877. FUN_00494470
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494470__FUN_00494470.c
878. FUN_004662E0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004662e0__FUN_004662e0.c
879. FUN_004C9360
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9360__FUN_004c9360.c
880. FUN_0041EF40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ef40__FUN_0041ef40.c
881. FUN_005567F5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567f5__FUN_005567f5.c
882. FUN_00596716
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596716__FUN_00596716.c
883. FUN_005608F6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005608f6__FUN_005608f6.c
884. FUN_0057ACB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057acb0__FUN_0057acb0.c
885. FUN_00575882
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00575882__FUN_00575882.c
886. FUN_0058FFEC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ffec__FUN_0058ffec.c
887. FUN_00581B30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581b30__FUN_00581b30.c
888. FUN_00568B00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568b00__FUN_00568b00.c
889. FUN_00443150
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00443150__FUN_00443150.c
890. FUN_0040E6A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e6a0__FUN_0040e6a0.c
891. FUN_004DC2D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc2d0__FUN_004dc2d0.c
892. FUN_00587720
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587720__FUN_00587720.c
893. FUN_0040E6D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e6d0__FUN_0040e6d0.c
894. FUN_00472D00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472d00__FUN_00472d00.c
895. FUN_0048D660
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d660__FUN_0048d660.c
896. FUN_004B1F50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1f50__FUN_004b1f50.c
897. FUN_004DCF50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf50__FUN_004dcf50.c
898. FUN_0052466C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052466c__FUN_0052466c.c
899. FUN_0057A760
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a760__FUN_0057a760.c
900. FUN_0058A380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a380__FUN_0058a380.c
901. FUN_00421990
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421990__FUN_00421990.c
902. FUN_004797C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004797c0__FUN_004797c0.c
903. FUN_0049A110
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a110__FUN_0049a110.c
904. FUN_004C7DE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7de0__FUN_004c7de0.c
905. FUN_0050D857
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d857__thunk_FUN_0050d84a.c
906. FUN_0054A5B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a5b0__FUN_0054a5b0.c
907. FUN_00550300
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550300__FUN_00550300.c
908. FUN_0046D610
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d610__FUN_0046d610.c
909. FUN_004C2C00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c00__FUN_004c2c00.c
910. FUN_00556260
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556260__FUN_00556260.c
911. FUN_00595F82
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595f82__FUN_00595f82.c
912. FUN_0045B400
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b400__FUN_0045b400.c
913. FUN_0047C9D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c9d0__FUN_0047c9d0.c
914. FUN_0049A180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a180__FUN_0049a180.c
915. FUN_004C4BB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4bb0__FUN_004c4bb0.c
916. FUN_00503B94
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503b94__FUN_00503b94.c
917. FUN_0054C2F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c2f0__FUN_0054c2f0.c
918. FUN_00598FD4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598fd4__FUN_00598fd4.c
919. FUN_00407EF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407ef0__FUN_00407ef0.c
920. FUN_00464A10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464a10__FUN_00464a10.c
921. FUN_00499CC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499cc0__FUN_00499cc0.c
922. FUN_004C2C20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c20__FUN_004c2c20.c
923. FUN_005016E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005016e0__FUN_005016e0.c
924. FUN_0053B6F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b6f0__FUN_0053b6f0.c
925. FUN_0058A32A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a32a__FUN_0058a32a.c
926. FUN_00408520
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408520__FUN_00408520.c
927. FUN_00465FF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465ff0__FUN_00465ff0.c
928. FUN_0048CA30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ca30__FUN_0048ca30.c
929. FUN_004A5BD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5bd0__FUN_004a5bd0.c
930. FUN_004DB4E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db4e0__FUN_004db4e0.c
931. FUN_0053BCE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bce0__FUN_0053bce0.c
932. FUN_00550760
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550760__FUN_00550760.c
933. FUN_00408740
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408740__FUN_00408740.c
934. FUN_00462330
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462330__FUN_00462330.c
935. FUN_00487900
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487900__FUN_00487900.c
936. FUN_004A0D90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0d90__FUN_004a0d90.c
937. FUN_004CE860
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce860__FUN_004ce860.c
938. FUN_0050C9A9
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c9a9__FUN_0050c9a9.c
939. FUN_00546430
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546430__FUN_00546430.c
940. FUN_0059AF50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059af50__FUN_0059af50.c
941. FUN_00425660
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00425660__FUN_00425660.c
942. FUN_004F3190
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f3190__FUN_004f3190.c
943. FUN_0058BD8F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bd8f____fassign.c
944. FUN_00421A70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a70__FUN_00421a70.c
945. FUN_00478350
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478350__FUN_00478350.c
946. FUN_004988C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988c0__FUN_004988c0.c
947. FUN_004BC270
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc270__FUN_004bc270.c
948. FUN_004F9420
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9420__FUN_004f9420.c
949. FUN_00534B00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534b00__FUN_00534b00.c
950. FUN_00584110
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584110__FUN_00584110.c
951. FUN_00406A90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406a90__FUN_00406a90.c
952. FUN_0054B4A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b4a0__FUN_0054b4a0.c
953. FUN_00534D50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534d50__FUN_00534d50.c
954. FUN_004D2E20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2e20__FUN_004d2e20.c
955. FUN_004A1F80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1f80__FUN_004a1f80.c
956. FUN_004893C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004893c0__FUN_004893c0.c
957. FUN_0046B580
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b580__FUN_0046b580.c
958. FUN_0057B0D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b0d0__FUN_0057b0d0.c
959. FUN_004DD4E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4e0__FUN_004dd4e0.c
960. FUN_00517AC5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ac5__FUN_00517ac5.c
961. FUN_0055C7B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c7b0__FUN_0055c7b0.c
962. FUN_0050DD3A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd3a__thunk_FUN_0050dd0c.c
963. FUN_0059C8D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8d0__Unwind_0059c8d0.c
964. FUN_00426CC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426cc0__FUN_00426cc0.c
965. FUN_004799A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004799a0__FUN_004799a0.c
966. FUN_00499260
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499260__FUN_00499260.c
967. FUN_004BE180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be180__FUN_004be180.c
968. FUN_004FC9A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc9a0__FUN_004fc9a0.c
969. FUN_00536FD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536fd0__FUN_00536fd0.c
970. FUN_005883E5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005883e5__FUN_005883e5.c
971. FUN_0059C504
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c504__Unwind_0059c504.c
972. FUN_004582C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582c0__FUN_004582c0.c
973. FUN_0047BE70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be70__FUN_0047be70.c
974. FUN_00499E50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e50__FUN_00499e50.c
975. FUN_004C2FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fb0__FUN_004c2fb0.c
976. FUN_00502C28
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502c28__FUN_00502c28.c
977. FUN_0053C210
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c210__FUN_0053c210.c
978. FUN_0058A9DA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a9da__FUN_0058a9da.c
979. FUN_00597568
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597568_____add_12.c
980. FUN_0045C400
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c400__FUN_0045c400.c
981. FUN_004858E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004858e0__FUN_004858e0.c
982. FUN_0049AF30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049af30__FUN_0049af30.c
983. FUN_004C9280
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9280__FUN_004c9280.c
984. FUN_0050B727
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b727__FUN_0050b727.c
985. FUN_00543A80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a80__FUN_00543a80.c
986. FUN_00599B1C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599b1c__FUN_00599b1c.c
987. FUN_00411570
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411570__FUN_00411570.c
988. FUN_0047F370
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f370__FUN_0047f370.c
989. FUN_0049A3B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a3b0__FUN_0049a3b0.c
990. FUN_004C7C00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c00__FUN_004c7c00.c
991. FUN_0050AE76
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae76__FUN_0050ae76.c
992. FUN_00540150
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540150__FUN_00540150.c
993. FUN_0059D99E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d99e__FUN_0059d99e.c
994. FUN_00423459
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423459__FUN_00423459.c
995. FUN_004B4460
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4460__FUN_004b4460.c
996. FUN_00542490
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542490__FUN_00542490.c
997. FUN_005884ED
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884ed___rand.c
998. FUN_004B0170
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0170__FUN_004b0170.c
999. FUN_00563230
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563230__FUN_00563230.c
1000. FUN_00459990
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459990__FUN_00459990.c
1001. FUN_00485A90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485a90__FUN_00485a90.c
1002. FUN_0049B020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b020__FUN_0049b020.c
1003. FUN_004C94D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c94d0__FUN_004c94d0.c
1004. FUN_0050B797
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b797__FUN_0050b797.c
1005. FUN_005424E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005424e0__FUN_005424e0.c
1006. FUN_00598E07
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e07__FUN_00598e07.c
1007. FUN_0040B450
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b450__FUN_0040b450.c
1008. FUN_004668E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004668e0__FUN_004668e0.c
1009. FUN_0048D4B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d4b0__FUN_0048d4b0.c
1010. FUN_004B0220
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0220__FUN_004b0220.c
1011. FUN_004D7FF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7ff0__FUN_004d7ff0.c
1012. FUN_00511F70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511f70__FUN_00511f70.c
1013. FUN_0054C190
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c190__FUN_0054c190.c
1014. FUN_0040A610
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a610__FUN_0040a610.c
1015. FUN_0046B5C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b5c0__FUN_0046b5c0.c
1016. FUN_00491E80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e80__FUN_00491e80.c
1017. FUN_0059C45A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c45a__Unwind_0059c45a.c
1018. FUN_0059D1D8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1d8__Unwind_0059d1d8.c
1019. FUN_0058C07F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c07f____cfltcvt.c
1020. FUN_0059D414
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d414__Unwind_0059d414.c
1021. FUN_0059CE76
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce76__Unwind_0059ce76.c
1022. FUN_0059CC93
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc93__Unwind_0059cc93.c
1023. FUN_00581D40
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581d40__FUN_00581d40.c
1024. FUN_00582190
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582190__FUN_00582190.c
1025. FUN_00500210
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500210__FUN_00500210.c
1026. FUN_0051BAD1
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bad1__FUN_0051bad1.c
1027. FUN_00515BB0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515bb0__FUN_00515bb0.c
1028. FUN_00561E30
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561e30__FUN_00561e30.c
1029. FUN_0059869C
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059869c__WSAStartup.c
1030. FUN_0057B840
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b840__FUN_0057b840.c
1031. FUN_00406CC0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406cc0__FUN_00406cc0.c

## FOR EACH FUNCTION

1. Find the `## FUN_XXXXXXXX` entry in the doc file (path given in your list)
2. Read the actual .c source file (path given in your list)
3. Compare EVERY claim in the doc entry against the .c source:

   **Check globals:** Does .c actually reference each claimed DAT_ address?
   **Check direction:** Entry says "reads DAT_X" — does .c read or write it?
   **Check struct offsets:** Claimed type (float/int/double) must match .c dereference pattern.
     `*(double *)(ptr + 0xXXX)` = double. `*(int *)(ptr + 0xXXX)` = int.
   **Check called functions:** Does .c actually call each claimed FUN_ address?
   **Check constants:** Are numeric thresholds and values accurate?
   **Check moddability:** "configurable" requires a config/field-name string literal in .c.

4. Write one block per function:

If CORRECT (all claims verified):
```
## FUN_XXXXXXXX — PASS
```

If ERRORS FOUND:
```
## FUN_XXXXXXXX — FAIL
Source: docs/XX-name.md

**Errors:**
- [WRONG_GLOBAL] Entry claims DAT_007c56a4 but .c does not reference it
- [WRONG_TYPE] Entry claims +0x1330 is double but .c shows *(int *)(ptr + 0x1330)
- [WRONG_DIRECTION] Entry says "reads DAT_X" but .c only writes to it
- [MISSING_GLOBAL] .c references DAT_YYYYYY not mentioned in entry
- [WRONG_CALL] Entry claims calls FUN_AAAAAA but .c does not call it
- [MISSING_CALL] .c calls FUN_BBBBBB not mentioned in entry
- [WRONG_CONST] Entry claims threshold 0.5 but .c shows 0.75
- [WRONG_MODDABILITY] Entry says configurable but no config string in .c

**Corrected entry:**
<!-- target: docs/XX-name.md -->
## FUN_XXXXXXXX — Corrected Name
[full corrected entry in standard format]
```

Write to disk after EVERY function. Do not batch.

## GHIDRA PATTERNS
- `*(double *)(ptr + 0x1330)` → offset +0x1330, type double
- `param_1[0x4a]` → int-indexed: byte offset = 0x4a × 4 = 0x128
- `unaff_EBX/ESI/EBP` → register-allocated `this` pointer
- `DAT_XXXXXXXX` → global variable

## RULES
0. NEVER move, rename, or delete any files.
1. Check EVERY function in your list — no skipping.
2. Only flag REAL errors — not style or wording differences.
3. If entry is correct, write PASS — one line only.
4. FAIL entries must include all error tags AND a full corrected replacement entry.
5. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_E.md after each function — never accumulate.
