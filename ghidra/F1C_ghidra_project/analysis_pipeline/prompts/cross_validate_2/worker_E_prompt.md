# WORKER E — F1C Cross-Validation Round 2

You are auditing ALL documented function entries across all docs/ files.
Round 2 uses updated docs/12 (2,356 globals) and docs/13 (6,910 lines) as ground truth.
Worker E of 20, items 1405–1755.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — global names
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct fields
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json` — call edges

## OUTPUT FILE
**APPEND** to (do NOT overwrite): %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_E.md

The file already contains completed verdicts. Before processing each function, check if `## FUN_XXXXXXXX` already appears in the output file — if so, skip it entirely.

## YOUR REMAINING FUNCTIONS (291)

1440. FUN_0052E1C0
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e1c0__thunk_FUN_0052d9b0.c

1465. FUN_00469D30
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00469d30__FUN_00469d30.c

1466. FUN_0046B830
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0046b830__FUN_0046b830.c

1467. FUN_0041AC50
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ac50__FUN_0041ac50.c

1468. FUN_0049B9A0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b9a0__FUN_0049b9a0.c

1469. FUN_004BC240
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc240__FUN_004bc240.c

1470. FUN_004D2170
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2170__FUN_004d2170.c

1471. FUN_004FEAF0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004feaf0__FUN_004feaf0.c

1472. FUN_0046AD50
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ad50__FUN_0046ad50.c

1473. FUN_00476660
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476660__FUN_00476660.c

1474. FUN_00596D81
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596d81__FUN_00596d81.c

1475. FUN_005542F0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005542f0__FUN_005542f0.c

1476. FUN_00588C7A
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588c7a__FUN_00588c7a.c

1477. FUN_0058AFE1
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058afe1__FUN_0058afe1.c

1478. FUN_0044F150
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f150__FUN_0044f150.c

1479. FUN_00508007
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508007__FUN_00508007.c

1480. FUN_00509959
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509959__FUN_00509959.c

1481. FUN_0051C2DB
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c2db__FUN_0051c2db.c

1482. FUN_00432650
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432650__FUN_00432650.c

1483. FUN_00541470
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541470__FUN_00541470.c

1484. FUN_004ED1C0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed1c0__FUN_004ed1c0.c

1485. FUN_004C6920
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6920__FUN_004c6920.c

1486. FUN_0054D030
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d030__FUN_0054d030.c

1487. FUN_004BE340
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be340__FUN_004be340.c

1488. FUN_0054FA90
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fa90__FUN_0054fa90.c

1489. FUN_005093F9
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005093f9__FUN_005093f9.c

1490. FUN_00537FE0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537fe0__FUN_00537fe0.c

1491. FUN_0052DC90
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052dc90__FUN_0052dc90.c

1492. FUN_004FE060
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fe060__FUN_004fe060.c

1493. FUN_004C1670
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1670__FUN_004c1670.c

1494. FUN_004C69B0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c69b0__FUN_004c69b0.c

1495. FUN_004EF560
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef560__FUN_004ef560.c

1496. FUN_004EF930
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef930__FUN_004ef930.c

1497. FUN_0042CEE0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042cee0__FUN_0042cee0.c

1498. FUN_0052835F
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052835f__FUN_0052835f.c

1499. FUN_00423E80
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423e80__FUN_00423e80.c

1500. FUN_004A5C80
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5c80__FUN_004a5c80.c

1501. FUN_004ED0F0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed0f0__FUN_004ed0f0.c

1502. FUN_005085C5
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005085c5__FUN_005085c5.c

1503. FUN_004E9630
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9630__FUN_004e9630.c

1504. FUN_0040F4B0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f4b0__FUN_0040f4b0.c

1505. FUN_0048C940
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c940__FUN_0048c940.c

1506. FUN_004D8220
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8220__FUN_004d8220.c

1507. FUN_00470F20
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470f20__sub_470F20.c

1508. FUN_004DDAD0
   doc: docs/07-pit-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004ddad0__FUN_004ddad0.c

1509. FUN_0041BE60
   doc: docs/07-pit-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041be60__FUN_0041be60.c

1510. FUN_0045C240
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045c240__FUN_0045c240.c

1511. FUN_004F6300
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004f6300__FUN_004f6300.c

1512. FUN_00468910
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00468910__FUN_00468910.c

1513. FUN_00407450
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407450__FUN_00407450.c

1514. FUN_00432980
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432980__FUN_00432980.c

1515. FUN_004B1600
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1600__FUN_004b1600.c

1516. FUN_004D6800
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6800__FUN_004d6800.c

1517. FUN_004A1F10
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1f10__FUN_004a1f10.c

1518. FUN_00559200
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559200__FUN_00559200.c

1519. FUN_00552D70
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552d70__FUN_00552d70.c

1520. FUN_0058C7FC
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c7fc__FUN_0058c7fc.c

1521. FUN_0058986E
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058986e__FUN_0058986e.c

1522. FUN_0059BAE8
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bae8__FUN_0059bae8.c

1523. FUN_00476030
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476030__FUN_00476030.c

1524. FUN_0059CB20
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb20__Unwind_0059cb20.c

1525. FUN_00536300
   doc: docs/08-file-formats.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536300__sub_536300.c

1526. FUN_004CDD80
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cdd80__FUN_004cdd80.c

1527. FUN_0040DB00
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0040db00__FUN_0040db00.c

1528. FUN_0045EB50
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045eb50__FUN_0045eb50.c

1529. FUN_004A3B50
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3b50__FUN_004a3b50.c

1530. FUN_004C5690
   doc: docs/09-track-system.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5690__FUN_004c5690.c

1531. FUN_00439210
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00439210__FUN_00439210.c

1532. FUN_00431AA0
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00431aa0__FUN_00431aa0.c

1533. FUN_004E0800
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0800__FUN_004e0800.c

1534. FUN_004F1630
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1630__FUN_004f1630.c

1535. FUN_004FAEC0
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004faec0__FUN_004faec0.c

1536. FUN_0051DFA8
   doc: docs/10-vehicle-physics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dfa8__FUN_0051dfa8.c

1538. FUN_0043E770
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e770__FUN_0043e770.c

1539. FUN_0044DFD0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dfd0__FUN_0044dfd0.c

1540. FUN_0044AF20
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044af20__FUN_0044af20.c

1541. FUN_0044E0F0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0f0__FUN_0044e0f0.c

1542. FUN_0044C6E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c6e0__FUN_0044c6e0.c

1543. FUN_0044DA90
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da90__FUN_0044da90.c

1544. FUN_0044F680
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f680__FUN_0044f680.c

1545. FUN_0044C860
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c860__FUN_0044c860.c

1546. FUN_0044DC10
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc10__FUN_0044dc10.c

1547. FUN_0044FBB0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fbb0__FUN_0044fbb0.c

1548. FUN_0044C650
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c650__FUN_0044c650.c

1549. FUN_0044EC90
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec90__FUN_0044ec90.c

1550. FUN_0044E000
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e000__FUN_0044e000.c

1551. FUN_0044E0C0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0c0__FUN_0044e0c0.c

1552. FUN_0044FEE0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fee0__FUN_0044fee0.c

1553. FUN_0044E060
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e060__FUN_0044e060.c

1554. FUN_0054EB40
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eb40__FUN_0054eb40.c

1555. FUN_004FB2E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb2e0__FUN_004fb2e0.c

1556. FUN_00561660
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561660__FUN_00561660.c

1557. FUN_004C73F0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c73f0__FUN_004c73f0.c

1558. FUN_004389B0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004389b0__FUN_004389b0.c

1559. FUN_005267A7
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005267a7__FUN_005267a7.c

1560. FUN_00432E50
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432e50__FUN_00432e50.c

1561. FUN_004326D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004326d0__FUN_004326d0.c

1562. FUN_0047A290
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a290__FUN_0047a290.c

1563. FUN_0043E5D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e5d0__FUN_0043e5d0.c

1564. FUN_00430600
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00430600__FUN_00430600.c

1565. FUN_00448510
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448510__FUN_00448510.c

1566. FUN_004B31A0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b31a0__FUN_004b31a0.c

1567. FUN_005691D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005691d0__FUN_005691d0.c

1568. FUN_0050D615
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d615__FUN_0050d615.c

1569. FUN_0052401F
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052401f__sub_52401F.c

1570. FUN_0056C2C4
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c2c4__sub_56C2C4.c

1571. FUN_004DB130
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db130__sub_4DB130.c

1572. FUN_004CCDC0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ccdc0__FUN_004ccdc0.c

1573. FUN_004583B0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004583b0__FUN_004583b0.c

1574. FUN_00489970
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489970__FUN_00489970.c

1575. FUN_0048FEE0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fee0__FUN_0048fee0.c

1576. FUN_00499A00
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a00__FUN_00499a00.c

1577. FUN_00560547
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560547__FUN_00560547.c

1578. FUN_0050B47E
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b47e__FUN_0050b47e.c

1579. FUN_00512894
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512894__FUN_00512894.c

1580. FUN_0051CF80
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cf80__FUN_0051cf80.c

1581. FUN_0054F830
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f830__FUN_0054f830.c

1582. FUN_00542050
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542050__FUN_00542050.c

1583. FUN_004CFCC0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cfcc0__FUN_004cfcc0.c

1584. FUN_0044D3D0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d3d0__FUN_0044d3d0.c

1585. FUN_00516990
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516990__FUN_00516990.c

1586. FUN_0048F1A0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f1a0__FUN_0048f1a0.c

1587. FUN_00558DC0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558dc0__FUN_00558dc0.c

1588. FUN_0050F0BF
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f0bf__FUN_0050f0bf.c

1589. FUN_00485960
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485960__FUN_00485960.c

1590. FUN_0050AE92
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae92__FUN_0050ae92.c

1591. FUN_0047F3F0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f3f0__FUN_0047f3f0.c

1592. FUN_005424C0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005424c0__FUN_005424c0.c

1593. FUN_004D99E0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d99e0__FUN_004d99e0.c

1594. FUN_0046E1B0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e1b0__sub_46E1B0.c

1595. FUN_004DB0B0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db0b0__sub_4DB0B0.c

1596. FUN_00592DFA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592dfa__FUN_00592dfa.c

1597. FUN_00599560
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599560__FUN_00599560.c

1598. FUN_0058E290
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e290__FUN_0058e290.c

1599. FUN_0058C255
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c255__FUN_0058c255.c

1600. FUN_0056F818
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f818__FUN_0056f818.c

1601. FUN_005939F9
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005939f9__FUN_005939f9.c

1602. FUN_00565BB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565bb0__FUN_00565bb0.c

1603. FUN_005895A2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005895a2__FUN_005895a2.c

1604. FUN_005033A5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005033a5__FUN_005033a5.c

1605. FUN_00406060
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406060__FUN_00406060.c

1606. FUN_004C0370
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0370__FUN_004c0370.c

1607. FUN_0055BB20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb20__FUN_0055bb20.c

1608. FUN_00404FE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404fe0__FUN_00404fe0.c

1609. FUN_0046A4E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a4e0__FUN_0046a4e0.c

1610. FUN_00487690
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487690__FUN_00487690.c

1611. FUN_004A1AC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1ac0__FUN_004a1ac0.c

1612. FUN_004D7AD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7ad0__FUN_004d7ad0.c

1613. FUN_00515D26
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515d26__FUN_00515d26.c

1614. FUN_0055BDC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bdc0__FUN_0055bdc0.c

1615. FUN_00566CF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566cf0__FUN_00566cf0.c

1616. FUN_004119D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004119d0__FUN_004119d0.c

1617. FUN_00474C50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474c50__FUN_00474c50.c

1618. FUN_00498F60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498f60__FUN_00498f60.c

1619. FUN_004C03C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c03c0__FUN_004c03c0.c

1620. FUN_0050B228
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b228__FUN_0050b228.c

1621. FUN_00546200
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546200__FUN_00546200.c

1622. FUN_0059C5EE
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5ee__Unwind_0059c5ee.c

1623. FUN_0045CF30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cf30__FUN_0045cf30.c

1624. FUN_004B47A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b47a0__FUN_004b47a0.c

1625. FUN_00548E00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548e00__FUN_00548e00.c

1626. FUN_00587250
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587250__FUN_00587250.c

1627. FUN_00423DB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423db0__FUN_00423db0.c

1628. FUN_00479820
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479820__FUN_00479820.c

1629. FUN_00498F80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498f80__FUN_00498f80.c

1630. FUN_004BD970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd970__FUN_004bd970.c

1631. FUN_004FB8E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb8e0__FUN_004fb8e0.c

1632. FUN_005473C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005473c0__FUN_005473c0.c

1633. FUN_00551F10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551f10__FUN_00551f10.c

1634. FUN_00486080
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486080__FUN_00486080.c

1635. FUN_00461480
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461480__FUN_00461480.c

1636. FUN_00498650
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498650__FUN_00498650.c

1637. FUN_004BB950
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb950__FUN_004bb950.c

1638. FUN_004F91B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f91b0__FUN_004f91b0.c

1639. FUN_005317C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005317c0__FUN_005317c0.c

1640. FUN_00583680
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583680__FUN_00583680.c

1641. FUN_00404820
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404820__FUN_00404820.c

1642. FUN_00462310
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462310__FUN_00462310.c

1643. FUN_00487830
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487830__FUN_00487830.c

1644. FUN_004A0D30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0d30__FUN_004a0d30.c

1645. FUN_004D5960
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5960__FUN_004d5960.c

1646. FUN_0052D970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d970__FUN_0052d970.c

1647. FUN_0059CD40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd40__Unwind_0059cd40.c

1648. FUN_004054E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004054e0__FUN_004054e0.c

1649. FUN_0045BF50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf50__FUN_0045bf50.c

1650. FUN_00485630
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485630__FUN_00485630.c

1651. FUN_0049AA70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aa70__FUN_0049aa70.c

1652. FUN_004C8210
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8210__FUN_004c8210.c

1653. FUN_0050A8D9
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a8d9__FUN_0050a8d9.c

1654. FUN_0053D880
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d880__FUN_0053d880.c

1655. FUN_00594BCD
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594bcd__FUN_00594bcd.c

1656. FUN_00410AD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410ad0__FUN_00410ad0.c

1657. FUN_004C9D50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9d50__FUN_004c9d50.c

1658. FUN_00586CA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586ca0__FUN_00586ca0.c

1659. FUN_00415700
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415700__FUN_00415700.c

1660. FUN_00473BD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473bd0__FUN_00473bd0.c

1661. FUN_00495080
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495080__FUN_00495080.c

1662. FUN_004B9880
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9880__FUN_004b9880.c

1663. FUN_004E9537
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9537__FUN_004e9537.c

1664. FUN_0051EC00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ec00__FUN_0051ec00.c

1665. FUN_00566DB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566db0__FUN_00566db0.c

1666. FUN_0059083B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059083b____ctrandisp1.c

1667. FUN_0059985C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059985c__FUN_0059985c.c

1668. FUN_0051EC40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ec40__FUN_0051ec40.c

1669. FUN_004FC870
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc870__FUN_004fc870.c

1670. FUN_004BA780
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba780__FUN_004ba780.c

1671. FUN_00499910
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499910__FUN_00499910.c

1672. FUN_0047A190
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a190__FUN_0047a190.c

1673. FUN_0050D0BC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0bc__thunk_FUN_0050d0af.c

1674. FUN_004DBAB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbab0__FUN_004dbab0.c

1675. FUN_00517AC5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ac5__FUN_00517ac5.c

1676. FUN_00579FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579fb0__FUN_00579fb0.c

1677. FUN_00565ED0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565ed0__FUN_00565ed0.c

1678. FUN_0059CFE8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfe8__Unwind_0059cfe8.c

1679. FUN_0045C3C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c3c0__FUN_0045c3c0.c

1680. FUN_00485720
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485720__FUN_00485720.c

1681. FUN_0049AE40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ae40__FUN_0049ae40.c

1682. FUN_004C8560
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8560__FUN_004c8560.c

1683. FUN_0050AE22
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae22__FUN_0050ae22.c

1684. FUN_0053FED0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fed0__FUN_0053fed0.c

1685. FUN_00598731
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598731__FUN_00598731.c

1686. FUN_00404D20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d20__FUN_00404d20.c

1687. FUN_004618D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004618d0__FUN_004618d0.c

1688. FUN_00487250
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487250__FUN_00487250.c

1689. FUN_0049F710
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f710__FUN_0049f710.c

1690. FUN_004CAD30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cad30__FUN_004cad30.c

1691. FUN_0050C20D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c20d__FUN_0050c20d.c

1692. FUN_00543A60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a60__FUN_00543a60.c

1693. FUN_00599942
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599942__FUN_00599942.c

1694. FUN_00404D30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d30__FUN_00404d30.c

1695. FUN_00464D30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464d30__FUN_00464d30.c

1696. FUN_0048B910
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b910__FUN_0048b910.c

1697. FUN_004A8B30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8b30__FUN_004a8b30.c

1698. FUN_004D7E40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e40__FUN_004d7e40.c

1699. FUN_00513374
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513374__FUN_00513374.c

1700. FUN_0054FB90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fb90__FUN_0054fb90.c

1701. FUN_0057B630
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b630__FUN_0057b630.c

1702. FUN_00423250
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423250__FUN_00423250.c

1703. FUN_00489500
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489500__FUN_00489500.c

1704. FUN_004A2770
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2770__FUN_004a2770.c

1705. FUN_004D7020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7020__FUN_004d7020.c

1706. FUN_0051189C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051189c__FUN_0051189c.c

1707. FUN_0054BDA0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bda0__FUN_0054bda0.c

1708. FUN_005884E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884e0__FUN_005884e0.c

1709. FUN_0047C0A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c0a0__FUN_0047c0a0.c

1710. FUN_004D4800
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4800__FUN_004d4800.c

1711. FUN_00553620
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553620__FUN_00553620.c

1712. FUN_0059AE07
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae07__FUN_0059ae07.c

1713. FUN_00517F35
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f35__FUN_00517f35.c

1714. FUN_00403F70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403f70__FUN_00403f70.c

1715. FUN_00466300
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466300__FUN_00466300.c

1716. FUN_0048D3F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3f0__FUN_0048d3f0.c

1717. FUN_004B1C20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1c20__FUN_004b1c20.c

1718. FUN_004D9F80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9f80__FUN_004d9f80.c

1719. FUN_00513B51
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b51__FUN_00513b51.c

1720. FUN_0054FC70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc70__FUN_0054fc70.c

1721. FUN_0052D8C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8c0__thunk_FUN_0052d990.c

1722. FUN_00418A20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418a20__FUN_00418a20.c

1723. FUN_00474900
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474900__FUN_00474900.c

1724. FUN_00495790
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495790__FUN_00495790.c

1725. FUN_004B9D90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d90__FUN_004b9d90.c

1726. FUN_004EFFD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004effd0__FUN_004effd0.c

1727. FUN_00522CE2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522ce2__FUN_00522ce2.c

1728. FUN_00567D00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567d00__FUN_00567d00.c

1729. FUN_0041B970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b970__FUN_0041b970.c

1730. FUN_00486400
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486400__FUN_00486400.c

1731. FUN_004A1FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1fb0__FUN_004a1fb0.c

1732. FUN_0059C988
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c988__Unwind_0059c988.c

1733. FUN_0059C684
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c684__Unwind_0059c684.c

1734. FUN_0059C902
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c902__Unwind_0059c902.c

1735. FUN_0059C67A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c67a__Unwind_0059c67a.c

1736. FUN_0059D3A8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3a8__Unwind_0059d3a8.c

1737. FUN_0050E19E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e19e__FUN_0050e19e.c

1738. FUN_00522C2D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522c2d__sub_522C2D.c

1739. FUN_0058A0B6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a0b6__sub_58A0B6.c

1740. FUN_0052717C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052717c__sub_52717C.c

1741. FUN_005908B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005908b0__sub_5908B0.c

1742. FUN_0054EEC1
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eec1__sub_54EEC1.c

1743. FUN_0045C0A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c0a0__FUN_0045c0a0.c

1744. FUN_00406130
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406130__FUN_00406130.c

1745. FUN_00597388
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597388__FUN_00597388.c

1746. FUN_00585470
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585470__FUN_00585470.c

1747. FUN_004072E0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004072e0__FUN_004072e0.c

1748. FUN_00541120
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541120__FUN_00541120.c

1749. FUN_0059863C
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059863c__bind.c

1750. FUN_0059867E
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059867e__send.c

1751. FUN_005648D0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005648d0__FUN_005648d0.c

1752. FUN_00406CC0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406cc0__FUN_00406cc0.c

1753. FUN_004C9840
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9840__FUN_004c9840.c

1754. FUN_004319DA
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004319da__sub_4319DA.c

1755. FUN_0044E960
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e960__FUN_0044e960.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_E.md.
1. Check EVERY function — no skipping.
2. Only flag REAL errors, not style differences.
3. FAIL entries must include all error tags AND a full corrected entry.
