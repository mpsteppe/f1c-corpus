# WORKER H — F1C Cross-Validation Audit

You are auditing documented function entries against their actual Ghidra decompilation.
Worker H of 20, items 1444–1649.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_H.md

## YOUR FUNCTIONS (206)

1444. FUN_004A5FA0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5fa0__FUN_004a5fa0.c
1445. FUN_004FB2E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb2e0__FUN_004fb2e0.c
1446. FUN_0044DFD0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dfd0__FUN_0044dfd0.c
1447. FUN_0044BC10
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044bc10__FUN_0044bc10.c
1448. FUN_0044CDA0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cda0__FUN_0044cda0.c
1449. FUN_0044E8D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e8d0__FUN_0044e8d0.c
1450. FUN_0044C740
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c740__FUN_0044c740.c
1451. FUN_0047C960
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c960__FUN_0047c960.c
1452. FUN_0044EA50
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea50__FUN_0044ea50.c
1453. FUN_0044DDC0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ddc0__FUN_0044ddc0.c
1454. FUN_0044C5E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c5e0__FUN_0044c5e0.c
1455. FUN_0044EBD0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ebd0__FUN_0044ebd0.c
1456. FUN_0044DF40
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044df40__FUN_0044df40.c
1457. FUN_0044C710
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c710__FUN_0044c710.c
1458. FUN_0044F050
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f050__FUN_0044f050.c
1459. FUN_0044DF10
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044df10__FUN_0044df10.c
1460. FUN_0044C7D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c7d0__FUN_0044c7d0.c
1461. FUN_00491C70
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491c70__FUN_00491c70.c
1462. FUN_0056C830
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c830__FUN_0056c830.c
1463. FUN_00459AE0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459ae0__FUN_00459ae0.c
1464. FUN_004B2DD0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2dd0__FUN_004b2dd0.c
1465. FUN_00435E60
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435e60__FUN_00435e60.c
1466. FUN_0040EF70
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ef70__FUN_0040ef70.c
1467. FUN_00448330
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448330__FUN_00448330.c
1468. FUN_00448EC0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448ec0__FUN_00448ec0.c
1469. FUN_0043EBD0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ebd0__FUN_0043ebd0.c
1470. FUN_00449EB7
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449eb7__FUN_00449eb7.c
1471. FUN_004390A0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004390a0__FUN_004390a0.c
1472. FUN_004482D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004482d0__FUN_004482d0.c
1473. FUN_0043BBD0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043bbd0__FUN_0043bbd0.c
1474. FUN_004E4570
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4570__FUN_004e4570.c
1475. FUN_00569860
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569860__FUN_00569860.c
1476. FUN_0056A240
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a240__FUN_0056a240.c
1477. FUN_00411840
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411840__FUN_00411840.c
1478. FUN_00486240
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486240__FUN_00486240.c
1479. FUN_00489A10
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489a10__FUN_00489a10.c
1480. FUN_0048FEE0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fee0__FUN_0048fee0.c
1481. FUN_004986A0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004986a0__FUN_004986a0.c
1482. FUN_0055DA50
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055da50__FUN_0055da50.c
1483. FUN_0050B8A9
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b8a9__FUN_0050b8a9.c
1484. FUN_0048A240
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a240__FUN_0048a240.c
1485. FUN_0051941D
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051941d__FUN_0051941d.c
1486. FUN_00543FA0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543fa0__FUN_00543fa0.c
1487. FUN_00512ACC
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512acc__FUN_00512acc.c
1488. FUN_00548190
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548190__FUN_00548190.c
1489. FUN_005159F5
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005159f5__FUN_005159f5.c
1490. FUN_0050E6D3
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e6d3__FUN_0050e6d3.c
1491. FUN_0050696C
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050696c__thunk_FUN_0050653e.c
1492. FUN_0051E0DC
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e0dc__FUN_0051e0dc.c
1493. FUN_0050D9A5
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d9a5__FUN_0050d9a5.c
1494. FUN_00586D70
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586d70__FUN_00586d70.c
1495. FUN_004993D0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004993d0__FUN_004993d0.c
1496. FUN_004742A0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004742a0__FUN_004742a0.c
1497. FUN_004DC1A0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc1a0__FUN_004dc1a0.c
1498. FUN_00448300
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448300__FUN_00448300.c
1499. FUN_00595801
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595801__FUN_00595801.c
1500. FUN_00556760
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556760__FUN_00556760.c
1501. FUN_00585130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585130__FUN_00585130.c
1502. FUN_0058BCCF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bccf__FUN_0058bccf.c
1503. FUN_0058CA19
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ca19__FUN_0058ca19.c
1504. FUN_005574B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005574b0__FUN_005574b0.c
1505. FUN_0058F362
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f362__FUN_0058f362.c
1506. FUN_0058C724
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c724__FUN_0058c724.c
1507. FUN_00558CB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558cb0__FUN_00558cb0.c
1508. FUN_0045CBF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cbf0__FUN_0045cbf0.c
1509. FUN_0050D748
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d748__FUN_0050d748.c
1510. FUN_005992D3
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005992d3__FUN_005992d3.c
1511. FUN_0041F180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f180__FUN_0041f180.c
1512. FUN_004781A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004781a0__FUN_004781a0.c
1513. FUN_004910D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004910d0__FUN_004910d0.c
1514. FUN_004B46F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b46f0__FUN_004b46f0.c
1515. FUN_004F8280
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8280__FUN_004f8280.c
1516. FUN_005355A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005355a0__FUN_005355a0.c
1517. FUN_00587880
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587880__FUN_00587880.c
1518. FUN_00599D17
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d17__FUN_00599d17.c
1519. FUN_0045B360
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b360__FUN_0045b360.c
1520. FUN_0047C910
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c910__FUN_0047c910.c
1521. FUN_004A03F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a03f0__FUN_004a03f0.c
1522. FUN_004D0EC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0ec0__FUN_004d0ec0.c
1523. FUN_0051212E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051212e__FUN_0051212e.c
1524. FUN_0055BDD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bdd0__FUN_0055bdd0.c
1525. FUN_00568CF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568cf0__FUN_00568cf0.c
1526. FUN_004797F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004797f0__FUN_004797f0.c
1527. FUN_004D7BF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7bf0__FUN_004d7bf0.c
1528. FUN_00586E50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586e50__FUN_00586e50.c
1529. FUN_00404790
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404790__FUN_00404790.c
1530. FUN_00461470
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461470__FUN_00461470.c
1531. FUN_004868C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004868c0__FUN_004868c0.c
1532. FUN_0049EC60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ec60__FUN_0049ec60.c
1533. FUN_004C9B70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9b70__FUN_004c9b70.c
1534. FUN_0050B830
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b830__FUN_0050b830.c
1535. FUN_005622B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005622b0__FUN_005622b0.c
1536. FUN_00467260
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00467260__FUN_00467260.c
1537. FUN_0040D450
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d450__FUN_0040d450.c
1538. FUN_00568E60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568e60__thunk_FUN_00568f20.c
1539. FUN_0049D150
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d150__FUN_0049d150.c
1540. FUN_004C8D90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8d90__FUN_004c8d90.c
1541. FUN_0050B37D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b37d__FUN_0050b37d.c
1542. FUN_00541090
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541090__FUN_00541090.c
1543. FUN_005975F4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005975f4__FUN_005975f4.c
1544. FUN_0040E8B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e8b0__FUN_0040e8b0.c
1545. FUN_0046D6A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d6a0__FUN_0046d6a0.c
1546. FUN_00490250
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490250__FUN_00490250.c
1547. FUN_004B2A80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a80__FUN_004b2a80.c
1548. FUN_004DFA60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfa60__FUN_004dfa60.c
1549. FUN_0054E0E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e0e0__FUN_0054e0e0.c
1550. FUN_0058A5D8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a5d8__FUN_0058a5d8.c
1551. FUN_0056F090
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f090__FUN_0056f090.c
1552. FUN_00466050
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466050__FUN_00466050.c
1553. FUN_0048CA50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ca50__FUN_0048ca50.c
1554. FUN_004A5C10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5c10__FUN_004a5c10.c
1555. FUN_004D7CF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7cf0__FUN_004d7cf0.c
1556. FUN_005111D3
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005111d3__FUN_005111d3.c
1557. FUN_0054B3F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b3f0__FUN_0054b3f0.c
1558. FUN_0059D4C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4c0__Unwind_0059d4c0.c
1559. FUN_00463C40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463c40__FUN_00463c40.c
1560. FUN_00513E5D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513e5d__FUN_00513e5d.c
1561. FUN_005972BD
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005972bd__FUN_005972bd.c
1562. FUN_00457EE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457ee0__FUN_00457ee0.c
1563. FUN_0047BB40
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bb40__FUN_0047bb40.c
1564. FUN_00499E00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e00__FUN_00499e00.c
1565. FUN_004C2D30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2d30__FUN_004c2d30.c
1566. FUN_0050210E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050210e__FUN_0050210e.c
1567. FUN_0053C150
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c150__FUN_0053c150.c
1568. FUN_0058A870
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a870____aullshr.c
1569. FUN_0040DBC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dbc0__FUN_0040dbc0.c
1570. FUN_00557280
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557280__FUN_00557280.c
1571. FUN_0051166B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051166b__FUN_0051166b.c
1572. FUN_004D8A30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8a30__FUN_004d8a30.c
1573. FUN_004B19F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b19f0__FUN_004b19f0.c
1574. FUN_0048E300
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e300__FUN_0048e300.c
1575. FUN_004623B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004623b0__FUN_004623b0.c
1576. FUN_004BA790
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba790__FUN_004ba790.c
1577. FUN_004F62E6
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f62e6__FUN_004f62e6.c
1578. FUN_00527EED
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527eed__FUN_00527eed.c
1579. FUN_00579FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579fb0__FUN_00579fb0.c
1580. FUN_00564640
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564640__GetTickCount.c
1581. FUN_0059CE8C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce8c__Unwind_0059ce8c.c
1582. FUN_0045BA60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ba60__FUN_0045ba60.c
1583. FUN_0047F180
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f180__FUN_0047f180.c
1584. FUN_0049A2F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2f0__FUN_0049a2f0.c
1585. FUN_004C6760
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6760__FUN_004c6760.c
1586. FUN_00504640
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504640__FUN_00504640.c
1587. FUN_0053CED0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ced0__FUN_0053ced0.c
1588. FUN_0059532B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059532b__FUN_0059532b.c
1589. FUN_004010B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004010b0__FUN_004010b0.c
1590. FUN_0045E5B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5b0__FUN_0045e5b0.c
1591. FUN_00486480
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486480__FUN_00486480.c
1592. FUN_0049E170
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e170__FUN_0049e170.c
1593. FUN_004C9260
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9260__FUN_004c9260.c
1594. FUN_0050B462
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b462__FUN_0050b462.c
1595. FUN_005423E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005423e0__FUN_005423e0.c
1596. FUN_00598750
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598750__FUN_00598750.c
1597. FUN_00401130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401130__FUN_00401130.c
1598. FUN_00462530
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462530__FUN_00462530.c
1599. FUN_00487F10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f10__FUN_00487f10.c
1600. FUN_004A2220
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2220__FUN_004a2220.c
1601. FUN_004D47C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47c0__FUN_004d47c0.c
1602. FUN_0050F9AB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f9ab__FUN_0050f9ab.c
1603. FUN_00549380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549380__FUN_00549380.c
1604. FUN_0050E3DA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3da__thunk_FUN_0050e3cd.c
1605. FUN_0041EF00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ef00__FUN_0041ef00.c
1606. FUN_00487330
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487330__FUN_00487330.c
1607. FUN_0049F790
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f790__FUN_0049f790.c
1608. FUN_004CB4F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb4f0__FUN_004cb4f0.c
1609. FUN_0050D5F9
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d5f9__FUN_0050d5f9.c
1610. FUN_00547140
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547140__FUN_00547140.c
1611. FUN_005668B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005668b0__FUN_005668b0.c
1612. FUN_004646C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004646c0__FUN_004646c0.c
1613. FUN_004BF630
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf630__FUN_004bf630.c
1614. FUN_005487E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005487e0__FUN_005487e0.c
1615. FUN_00591E89
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e89__FUN_00591e89.c
1616. FUN_004D7920
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7920__FUN_004d7920.c
1617. FUN_0058A2CB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2cb__FUN_0058a2cb.c
1618. FUN_00460710
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460710__FUN_00460710.c
1619. FUN_004881F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004881f0__FUN_004881f0.c
1620. FUN_004A2840
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2840__FUN_004a2840.c
1621. FUN_004D4860
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4860__FUN_004d4860.c
1622. FUN_0050E342
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e342__FUN_0050e342.c
1623. FUN_00548850
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548850__FUN_00548850.c
1624. FUN_0059CA30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca30__Unwind_0059ca30.c
1625. FUN_0040F380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f380__FUN_0040f380.c
1626. FUN_0046F490
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f490__FUN_0046f490.c
1627. FUN_00490B90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490b90__FUN_00490b90.c
1628. FUN_004B2C80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c80__FUN_004b2c80.c
1629. FUN_004DCF20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf20__FUN_004dcf20.c
1630. FUN_00516974
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516974__FUN_00516974.c
1631. FUN_00559FB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559fb0__FUN_00559fb0.c
1632. FUN_0040EBD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ebd0__FUN_0040ebd0.c
1633. FUN_00475140
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475140__FUN_00475140.c
1634. FUN_00497890
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497890__FUN_00497890.c
1635. FUN_0059C5F8
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5f8__Unwind_0059c5f8.c
1636. FUN_0059D4E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4e0__Unwind_0059d4e0.c
1637. FUN_0059D5BC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5bc__Unwind_0059d5bc.c
1638. FUN_0058A7EC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a7ec____setjmp3.c
1639. FUN_0059CF4B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf4b__Unwind_0059cf4b.c
1640. FUN_0059D130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d130__Unwind_0059d130.c
1641. FUN_00581070
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581070__FUN_00581070.c
1642. FUN_0059A5E9
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a5e9__FUN_0059a5e9.c
1643. FUN_004F12E0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f12e0__FUN_004f12e0.c
1644. FUN_0051E3E7
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e3e7__FUN_0051e3e7.c
1645. FUN_00568210
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568210__FUN_00568210.c
1646. FUN_00563080
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563080__FUN_00563080.c
1647. FUN_0057D8D0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057d8d0__FUN_0057d8d0.c
1648. FUN_004C8D70
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8d70__FUN_004c8d70.c
1649. FUN_00405B50
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b50__FUN_00405b50.c

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
5. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_H.md after each function — never accumulate.
