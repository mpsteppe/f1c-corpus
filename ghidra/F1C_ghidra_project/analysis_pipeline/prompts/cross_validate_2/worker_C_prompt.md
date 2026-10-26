# WORKER C — F1C Cross-Validation Round 2

You are auditing ALL documented function entries across all docs/ files.
Round 2 uses updated docs/12 (2,356 globals) and docs/13 (6,910 lines) as ground truth.
Worker C of 20, items 703–1053.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — global names
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct fields
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json` — call edges

## OUTPUT FILE
**APPEND** to (do NOT overwrite): %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_C.md

The file already contains completed verdicts. Before processing each function, check if `## FUN_XXXXXXXX` already appears in the output file — if so, skip it entirely.

## YOUR REMAINING FUNCTIONS (196)

703. FUN_004024F0
   doc: docs/00-source-tree.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004024f0__FUN_004024f0.c

704. FUN_004C8A20
   doc: docs/00-source-tree.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8a20__FUN_004c8a20.c

705. FUN_004C8A20
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8a20__FUN_004c8a20.c

706. FUN_00404F30
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00404f30__FUN_00404f30.c

714. FUN_004A0AD0
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0ad0__FUN_004a0ad0.c

726. FUN_00593C9C
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593c9c__FUN_00593c9c.c

787. FUN_004C07F0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c07f0__FUN_004c07f0.c

788. FUN_004E0E20
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0e20__FUN_004e0e20.c

789. FUN_004E17C0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e17c0__FUN_004e17c0.c

790. FUN_004BBFC0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbfc0__FUN_004bbfc0.c

791. FUN_00548D40
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548d40__FUN_00548d40.c

792. FUN_00542400
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542400__FUN_00542400.c

793. FUN_004B5A30
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5a30__FUN_004b5a30.c

794. FUN_005087A2
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005087a2__FUN_005087a2.c

795. FUN_0054E240
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e240__FUN_0054e240.c

796. FUN_00512322
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512322__FUN_00512322.c

797. FUN_00508F3D
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508f3d__FUN_00508f3d.c

798. FUN_004B87A0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b87a0__FUN_004b87a0.c

799. FUN_004E23AD
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e23ad__FUN_004e23ad.c

800. FUN_0054D7A0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d7a0__FUN_0054d7a0.c

801. FUN_004C79E0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c79e0__FUN_004c79e0.c

802. FUN_004B9820
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9820__FUN_004b9820.c

803. FUN_004888F0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004888f0__FUN_004888f0.c

804. FUN_004D48B0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d48b0__FUN_004d48b0.c

805. FUN_004D9290
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9290__FUN_004d9290.c

814. FUN_004CDBF0
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cdbf0__FUN_004cdbf0.c

815. FUN_004A1B90
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b90__FUN_004a1b90.c

837. FUN_0044D070
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d070__FUN_0044d070.c

839. FUN_0044D190
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d190__FUN_0044d190.c

840. FUN_0044D460
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d460__FUN_0044d460.c

841. FUN_0044CB30
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb30__FUN_0044cb30.c

843. FUN_0044E4E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e4e0__FUN_0044e4e0.c

844. FUN_0044CCB0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ccb0__FUN_0044ccb0.c

846. FUN_0044C9E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c9e0__FUN_0044c9e0.c

847. FUN_0044DD90
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd90__FUN_0044dd90.c

875. FUN_0055DA50
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055da50__FUN_0055da50.c

894. FUN_00596A2E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596a2e__FUN_00596a2e.c

895. FUN_0059C30E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c30e__FUN_0059c30e.c

896. FUN_00566380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566380__FUN_00566380.c

897. FUN_0058AA6F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aa6f__FUN_0058aa6f.c

898. FUN_0058DFC1
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dfc1__FUN_0058dfc1.c

899. FUN_00560C10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560c10__FUN_00560c10.c

900. FUN_00567B10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567b10__FUN_00567b10.c

901. FUN_005572B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005572b0__FUN_005572b0.c

902. FUN_00500BC8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500bc8__FUN_00500bc8.c

903. FUN_00404030
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404030__FUN_00404030.c

904. FUN_004A0000
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0000__FUN_004a0000.c

905. FUN_0054C1A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c1a0__FUN_0054c1a0.c

906. FUN_0059CD60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd60__Unwind_0059cd60.c

907. FUN_00465160
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465160__FUN_00465160.c

908. FUN_00485DF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485df0__FUN_00485df0.c

909. FUN_0049B1C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b1c0__FUN_0049b1c0.c

910. FUN_004C9820
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9820__FUN_004c9820.c

911. FUN_00512114
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512114__FUN_00512114.c

912. FUN_0054C270
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c270__FUN_0054c270.c

913. FUN_005565B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005565b0__FUN_005565b0.c

914. FUN_0040E710
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e710__FUN_0040e710.c

915. FUN_00471540
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471540__FUN_00471540.c

916. FUN_00497250
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497250__FUN_00497250.c

917. FUN_004BB6B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb6b0__FUN_004bb6b0.c

918. FUN_00500F55
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500f55__FUN_00500f55.c

919. FUN_0053C6B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6b0__FUN_0053c6b0.c

920. FUN_00599475
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599475___Gninc.c

921. FUN_0045B3E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b3e0__FUN_0045b3e0.c

922. FUN_004B2A10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a10__FUN_004b2a10.c

923. FUN_0053D450
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d450__FUN_0053d450.c

924. FUN_0057BCC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bcc0__FUN_0057bcc0.c

925. FUN_0041FB10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fb10__FUN_0041fb10.c

926. FUN_00476D70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476d70__FUN_00476d70.c

927. FUN_004972B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004972b0__FUN_004972b0.c

928. FUN_004BAC40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bac40__FUN_004bac40.c

929. FUN_004F87C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f87c0__FUN_004f87c0.c

930. FUN_00543210
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543210__FUN_00543210.c

931. FUN_0059AD31
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ad31__FUN_0059ad31.c

932. FUN_0047CA30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047ca30__FUN_0047ca30.c

933. FUN_0045BEA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bea0__FUN_0045bea0.c

934. FUN_00495970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495970__FUN_00495970.c

935. FUN_004BA180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba180__FUN_004ba180.c

936. FUN_004F2B10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f2b10__FUN_004f2b10.c

937. FUN_005265DB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005265db__FUN_005265db.c

938. FUN_0056C740
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c740__FUN_0056c740.c

939. FUN_0059D290
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d290__Unwind_0059d290.c

940. FUN_0045D4C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d4c0__FUN_0045d4c0.c

941. FUN_004861A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004861a0__FUN_004861a0.c

942. FUN_0049D3F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d3f0__FUN_0049d3f0.c

943. FUN_004CE820
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce820__FUN_004ce820.c

944. FUN_0051EA5A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ea5a__FUN_0051ea5a.c

945. FUN_005997CB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997cb__FUN_005997cb.c

946. FUN_0059D4D8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4d8__Unwind_0059d4d8.c

947. FUN_00457CD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457cd0__FUN_00457cd0.c

948. FUN_0047B1B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b1b0__FUN_0047b1b0.c

949. FUN_00499DA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499da0__FUN_00499da0.c

950. FUN_004C2C40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c40__FUN_004c2c40.c

951. FUN_00501992
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00501992__FUN_00501992.c

952. FUN_0053BDE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bde0__FUN_0053bde0.c

953. FUN_0058A65F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a65f__FUN_0058a65f.c

954. FUN_0059B5C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b5c0__FUN_0059b5c0.c

955. FUN_004BBF70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbf70__FUN_004bbf70.c

956. FUN_00567940
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567940__FUN_00567940.c

957. FUN_00410AF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410af0__FUN_00410af0.c

958. FUN_0046FF40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ff40__FUN_0046ff40.c

959. FUN_00491680
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491680__FUN_00491680.c

960. FUN_004B3DB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3db0__FUN_004b3db0.c

961. FUN_004DD4C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4c0__FUN_004dd4c0.c

962. FUN_005179A2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005179a2__FUN_005179a2.c

963. FUN_0055C2A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c2a0__FUN_0055c2a0.c

964. FUN_0058BEF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bef0__FUN_0058bef0.c

965. FUN_0059525D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059525d__FUN_0059525d.c

966. FUN_005179E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005179e0__FUN_005179e0.c

967. FUN_004F8C00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c00__FUN_004f8c00.c

968. FUN_004B5040
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5040__FUN_004b5040.c

969. FUN_004988D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988d0__FUN_004988d0.c

970. FUN_00478690
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478690__FUN_00478690.c

971. FUN_00421A90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a90__FUN_00421a90.c

972. FUN_004D7DE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7de0__FUN_004d7de0.c

973. FUN_005151AF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005151af__FUN_005151af.c

974. FUN_0055C7B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c7b0__FUN_0055c7b0.c

975. FUN_00559760
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559760__FUN_00559760.c

976. FUN_0059CC9E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc9e__Unwind_0059cc9e.c

977. FUN_004582A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582a0__FUN_004582a0.c

978. FUN_0047BE00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be00__FUN_0047be00.c

979. FUN_00499E40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e40__FUN_00499e40.c

980. FUN_004C2FA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fa0__FUN_004c2fa0.c

981. FUN_00502BF4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502bf4__FUN_00502bf4.c

982. FUN_0053C200
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c200__FUN_0053c200.c

983. FUN_0058E0B4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e0b4__FUN_0058e0b4.c

984. FUN_0059CCC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ccc0__Unwind_0059ccc0.c

985. FUN_0045C3D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c3d0__FUN_0045c3d0.c

986. FUN_00485870
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485870__FUN_00485870.c

987. FUN_0049AEC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aec0__FUN_0049aec0.c

988. FUN_004C8580
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8580__FUN_004c8580.c

989. FUN_0050AE3E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae3e__FUN_0050ae3e.c

990. FUN_00540050
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540050__FUN_00540050.c

991. FUN_0059553A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059553a__FUN_0059553a.c

992. FUN_0059A43C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a43c__FUN_0059a43c.c

993. FUN_00462530
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462530__FUN_00462530.c

994. FUN_00487F10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f10__FUN_00487f10.c

995. FUN_004A2220
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2220__FUN_004a2220.c

996. FUN_004D47C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47c0__FUN_004d47c0.c

997. FUN_0050F9AB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f9ab__FUN_0050f9ab.c

998. FUN_00549380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549380__FUN_00549380.c

999. FUN_0050E3DA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3da__thunk_FUN_0050e3cd.c

1000. FUN_0041EF00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ef00__FUN_0041ef00.c

1001. FUN_00487330
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487330__FUN_00487330.c

1002. FUN_0049F790
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f790__FUN_0049f790.c

1003. FUN_004D0030
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0030__FUN_004d0030.c

1004. FUN_0050E281
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e281__FUN_0050e281.c

1005. FUN_005487A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005487a0__FUN_005487a0.c

1006. FUN_00568560
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568560__FUN_00568560.c

1007. FUN_00464EE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464ee0__FUN_00464ee0.c

1008. FUN_004C3020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3020__FUN_004c3020.c

1009. FUN_0054C030
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c030__FUN_0054c030.c

1010. FUN_00595310
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595310__FUN_00595310.c

1011. FUN_004F6F00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6f00__FUN_004f6f00.c

1012. FUN_0058C6F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c6f0____allmul.c

1013. FUN_00464720
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464720__FUN_00464720.c

1014. FUN_004895B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004895b0__FUN_004895b0.c

1015. FUN_004A46F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a46f0__FUN_004a46f0.c

1016. FUN_004D7930
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7930__FUN_004d7930.c

1017. FUN_0050FC58
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fc58__FUN_0050fc58.c

1018. FUN_0054A1C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a1c0__FUN_0054a1c0.c

1019. FUN_0059D0E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0e0__Unwind_0059d0e0.c

1020. FUN_004116C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004116c0__FUN_004116c0.c

1021. FUN_00470D30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470d30__FUN_00470d30.c

1022. FUN_00491A40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491a40__FUN_00491a40.c

1023. FUN_004B45E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b45e0__FUN_004b45e0.c

1024. FUN_004DE5F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de5f0__FUN_004de5f0.c

1025. FUN_0051923D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051923d__FUN_0051923d.c

1026. FUN_00560F10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560f10__FUN_00560f10.c

1027. FUN_004141F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004141f0__FUN_004141f0.c

1028. FUN_0047BD90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bd90__FUN_0047bd90.c

1029. FUN_0049ADC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049adc0__FUN_0049adc0.c

1030. FUN_0059C8E6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8e6__Unwind_0059c8e6.c

1031. FUN_00599D31
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d31__uflow.c

1032. FUN_0059C6F2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6f2__Unwind_0059c6f2.c

1033. FUN_0059C4A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4a0__Unwind_0059c4a0.c

1034. FUN_0059D2C7
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2c7__Unwind_0059d2c7.c

1035. FUN_0050CBB6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cbb6__FUN_0050cbb6.c

1036. FUN_00522A6C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522a6c__sub_522A6C.c

1037. FUN_0053C102
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c102__sub_53C102.c

1038. FUN_0051F0BE
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f0be__sub_51F0BE.c

1039. FUN_00521831
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521831__sub_521831.c

1040. FUN_005987DC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987dc__sub_5987DC.c

1041. FUN_00457D00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457d00__FUN_00457d00.c

1042. FUN_004F88A0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f88a0__FUN_004f88a0.c

1043. FUN_00556730
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556730__FUN_00556730.c

1044. FUN_00589B70
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589b70__FUN_00589b70.c

1045. FUN_00513482
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513482__FUN_00513482.c

1046. FUN_004B54E0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b54e0__FUN_004b54e0.c

1047. FUN_0057BEE0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bee0__FUN_0057bee0.c

1048. FUN_00598642
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598642__htonl.c

1049. FUN_0057A3F0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a3f0__FUN_0057a3f0.c

1050. FUN_00562FE0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562fe0__FUN_00562fe0.c

1051. FUN_0046DD30
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046dd30__FUN_0046dd30.c

1052. FUN_0044CC94
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc94__sub_44CC94.c

1053. FUN_00405B90
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b90__FUN_00405b90.c

## FOR EACH FUNCTION
1. Find `## FUN_XXXXXXXX` in the doc file
2. Read the actual .c source
3. Compare EVERY claim:
   - **Globals:** correct DAT_ address? correct name from docs/12?
   - **Direction:** reads vs writes?
   - **Types:** claimed double vs `*(int *)(ptr + 0xXXX)` in .c?
   - **Calls:** does .c actually call each claimed FUN_?
   - **Constants:** thresholds accurate?
   - **Moddability:** "configurable" requires config string literal in .c

If CORRECT: `## FUN_XXXXXXXX — PASS`

If ERRORS:
```
## FUN_XXXXXXXX — FAIL
Source: docs/XX-name.md

**Errors:**
- [WRONG_GLOBAL] / [WRONG_NAME] / [WRONG_TYPE] / [WRONG_DIRECTION]
- [MISSING_GLOBAL] / [WRONG_CALL] / [WRONG_CONST] / [WRONG_MODDABILITY]

**Corrected entry:**
<!-- target: docs/XX-name.md -->
## FUN_XXXXXXXX — Corrected Name
[full corrected entry]
```

Write to disk after EVERY function.

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_C.md.
1. Check EVERY function — no skipping.
2. Only flag REAL errors, not style differences.
3. FAIL entries must include all error tags AND a full corrected entry.
