# WORKER E — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker E of 20, items 1325–1655.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_E.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

1325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004010b0__FUN_004010b0.c
1326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004045f0__FUN_004045f0.c
1327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404ee8__sub_404EE8.c
1328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004057f0__FUN_004057f0.c
1329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004062b0__FUN_004062b0.c
1330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004071f0__sub_4071F0.c
1331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004080f0__FUN_004080f0.c
1332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408800__sub_408800.c
1333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040adb0__FUN_0040adb0.c
1334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c520__FUN_0040c520.c
1335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d240__FUN_0040d240.c
1336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dd80__FUN_0040dd80.c
1337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ebd0__FUN_0040ebd0.c
1338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410980__FUN_00410980.c
1339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411840__FUN_00411840.c
1340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414140__FUN_00414140.c
1341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414fe0__FUN_00414fe0.c
1342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418560__FUN_00418560.c
1343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418ee0__FUN_00418ee0.c
1344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ac50__FUN_0041ac50.c
1345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ed20__FUN_0041ed20.c
1346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004203d0__thunk_FUN_004201e0.c
1347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a10__FUN_00421a10.c
1348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423b10__FUN_00423b10.c
1349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426330__FUN_00426330.c
1350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042aca0__FUN_0042aca0.c
1351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bb80__FUN_0042bb80.c
1352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dce0__FUN_0042dce0.c
1353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ed44__sub_42ED44.c
1354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c70__FUN_00431c70.c
1355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432cf0__FUN_00432cf0.c
1356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434240__FUN_00434240.c
1357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004359a0__FUN_004359a0.c
1358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438ca0__FUN_00438ca0.c
1359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e890__FUN_0043e890.c
1360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441d60__FUN_00441d60.c
1361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004472b0__FUN_004472b0.c
1362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004486a0__FUN_004486a0.c
1363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004497e0__FUN_004497e0.c
1364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b040__FUN_0044b040.c
1365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c710__FUN_0044c710.c
1366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044caa0__FUN_0044caa0.c
1367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd10__FUN_0044cd10.c
1368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf94__sub_44CF94.c
1369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d2e0__FUN_0044d2e0.c
1370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d670__FUN_0044d670.c
1371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da30__FUN_0044da30.c
1372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ddf0__FUN_0044ddf0.c
1373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e1b0__FUN_0044e1b0.c
1374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e570__FUN_0044e570.c
1375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e930__FUN_0044e930.c
1376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ecf0__FUN_0044ecf0.c
1377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f6f6__sub_44F6F6.c
1378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452b10__FUN_00452b10.c
1379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455f90__FUN_00455f90.c
1380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004571e0__FUN_004571e0.c
1381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459330__FUN_00459330.c
1382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b580__FUN_0045b580.c
1383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045be50__FUN_0045be50.c
1384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c7c0__FUN_0045c7c0.c
1385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d510__FUN_0045d510.c
1386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460c30__FUN_00460c30.c
1387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461dc0__FUN_00461dc0.c
1388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462760__FUN_00462760.c
1389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463750__FUN_00463750.c
1390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004647d0__FUN_004647d0.c
1391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464f90__FUN_00464f90.c
1392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004661b0__FUN_004661b0.c
1393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00467340__FUN_00467340.c
1394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004698c0__FUN_004698c0.c
1395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b5e0__FUN_0046b5e0.c
1396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d680__FUN_0046d680.c
1397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046efe0__FUN_0046efe0.c
1398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004702f0__FUN_004702f0.c
1399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004717e0__FUN_004717e0.c
1400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473330__FUN_00473330.c
1401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474a10__FUN_00474a10.c
1402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475d90__FUN_00475d90.c
1403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476f90__FUN_00476f90.c
1404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477fa0__FUN_00477fa0.c
1405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478e80__FUN_00478e80.c
1406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479940__FUN_00479940.c
1407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a080__sub_47A080.c
1408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047abb0__FUN_0047abb0.c
1409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c6e0__FUN_0047c6e0.c
1410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047eff0__FUN_0047eff0.c
1411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004855d0__FUN_004855d0.c
1412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485eb0__FUN_00485eb0.c
1413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486540__FUN_00486540.c
1414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487060__FUN_00487060.c
1415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004876b0__FUN_004876b0.c
1416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004883d0__sub_4883D0.c
1417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489500__FUN_00489500.c
1418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489fd0__FUN_00489fd0.c
1419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b8f0__FUN_0048b8f0.c
1420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048cb00__FUN_0048cb00.c
1421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d740__FUN_0048d740.c
1422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e750__sub_48E750.c
1423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fb70__FUN_0048fb70.c
1424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004902a0__FUN_004902a0.c
1425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491170__FUN_00491170.c
1426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491bd0__FUN_00491bd0.c
1427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
1428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004950c0__FUN_004950c0.c
1429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495a20__FUN_00495a20.c
1430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497100__FUN_00497100.c
1431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979d0__FUN_004979d0.c
1432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498720__FUN_00498720.c
1433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498f60__FUN_00498f60.c
1434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499620__FUN_00499620.c
1435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b10__FUN_00499b10.c
1436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e90__FUN_00499e90.c
1437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a360__FUN_0049a360.c
1438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ad50__FUN_0049ad50.c
1439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b7a0__FUN_0049b7a0.c
1440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d280__FUN_0049d280.c
1441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e670__FUN_0049e670.c
1442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f1c0__FUN_0049f1c0.c
1443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0ad0__FUN_004a0ad0.c
1444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11d0__FUN_004a11d0.c
1445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1f10__FUN_004a1f10.c
1446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a35f0__FUN_004a35f0.c
1447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a55a0__FUN_004a55a0.c
1448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6200__FUN_004a6200.c
1449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004adf10__FUN_004adf10.c
1450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0ef0__FUN_004b0ef0.c
1451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1ac0__FUN_004b1ac0.c
1452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2310__FUN_004b2310.c
1453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2ae0__FUN_004b2ae0.c
1454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3b40__FUN_004b3b40.c
1455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4470__FUN_004b4470.c
1456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b51e0__FUN_004b51e0.c
1457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b67d0__FUN_004b67d0.c
1458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8150__FUN_004b8150.c
1459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9800__FUN_004b9800.c
1460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d90__FUN_004b9d90.c
1461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba900__FUN_004ba900.c
1462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb400__FUN_004bb400.c
1463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2a0__FUN_004bc2a0.c
1464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdb10__FUN_004bdb10.c
1465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf4f0__FUN_004bf4f0.c
1466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0b10__FUN_004c0b10.c
1467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2760__FUN_004c2760.c
1468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2dc0__FUN_004c2dc0.c
1469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4930__FUN_004c4930.c
1470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5db0__FUN_004c5db0.c
1471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c79e0__FUN_004c79e0.c
1472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8180__FUN_004c8180.c
1473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8d60__FUN_004c8d60.c
1474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9790__FUN_004c9790.c
1475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca2d0__FUN_004ca2d0.c
1476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ccb30__FUN_004ccb30.c
1477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cefa0__FUN_004cefa0.c
1478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1140__FUN_004d1140.c
1479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d23d0__FUN_004d23d0.c
1480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4a50__FUN_004d4a50.c
1481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7050__FUN_004d7050.c
1482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e40__FUN_004d7e40.c
1483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8a30__FUN_004d8a30.c
1484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dac30__FUN_004dac30.c
1485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db6f0__FUN_004db6f0.c
1486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc340__FUN_004dc340.c
1487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf80__FUN_004dcf80.c
1488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de5f0__FUN_004de5f0.c
1489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0d70__FUN_004e0d70.c
1490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e24a0__FUN_004e24a0.c
1491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e43d0__FUN_004e43d0.c
1492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e7f39__FUN_004e7f39.c
1493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea930__FUN_004ea930.c
1494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed960__FUN_004ed960.c
1495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004effd0__FUN_004effd0.c
1496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1aa0__FUN_004f1aa0.c
1497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6720__FUN_004f6720.c
1498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f7440__FUN_004f7440.c
1499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c90__FUN_004f8c90.c
1500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9b30__FUN_004f9b30.c
1501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc280__FUN_004fc280.c
1502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff040__FUN_004ff040.c
1503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005001f0__FUN_005001f0.c
1504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00501992__FUN_00501992.c
1505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503888__FUN_00503888.c
1506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005054ec__FUN_005054ec.c
1507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507779__FUN_00507779.c
1508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508a48__FUN_00508a48.c
1509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509b8e__FUN_00509b8e.c
1510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a6e5__FUN_0050a6e5.c
1511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b1d4__FUN_0050b1d4.c
1512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b75f__FUN_0050b75f.c
1513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c20d__FUN_0050c20d.c
1514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c85d__FUN_0050c85d.c
1515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d563__FUN_0050d563.c
1516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd3a__thunk_FUN_0050dd0c.c
1517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e342__FUN_0050e342.c
1518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f199__FUN_0050f199.c
1519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005107fb__FUN_005107fb.c
1520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511869__FUN_00511869.c
1521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005123b3__FUN_005123b3.c
1522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513bd1__FUN_00513bd1.c
1523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515303__FUN_00515303.c
1524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515f23__FUN_00515f23.c
1525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516c0c__FUN_00516c0c.c
1526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ec8__FUN_00517ec8.c
1527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519828__sub_519828.c
1528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051af57__FUN_0051af57.c
1529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c237__FUN_0051c237.c
1530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d6d2__FUN_0051d6d2.c
1531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e8d6__FUN_0051e8d6.c
1532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f5f0__sub_51F5F0.c
1533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005207ce__sub_5207CE.c
1534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052243a__sub_52243A.c
1535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00525e9a__FUN_00525e9a.c
1536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527f21__FUN_00527f21.c
1537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052a5d7__FUN_0052a5d7.c
1538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df10__FUN_0052df10.c
1539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e6f0__FUN_0052e6f0.c
1540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535220__FUN_00535220.c
1541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005365d0__sub_5365D0.c
1542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00538940__FUN_00538940.c
1543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053acf0__sub_53ACF0.c
1544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b5b0__FUN_0053b5b0.c
1545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c630__FUN_0053c630.c
1546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d260__FUN_0053d260.c
1547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053eb70__FUN_0053eb70.c
1548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540f90__FUN_00540f90.c
1549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541b70__FUN_00541b70.c
1550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542650__FUN_00542650.c
1551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a30__FUN_00543a30.c
1552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545340__FUN_00545340.c
1553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546010__FUN_00546010.c
1554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005472b0__FUN_005472b0.c
1555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548850__FUN_00548850.c
1556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005492b0__FUN_005492b0.c
1557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a710__FUN_0054a710.c
1558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bb40__FUN_0054bb40.c
1559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c2a0__FUN_0054c2a0.c
1560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e1a0__FUN_0054e1a0.c
1561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fae0__FUN_0054fae0.c
1562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550080__FUN_00550080.c
1563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005510f0__FUN_005510f0.c
1564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551eb0__FUN_00551eb0.c
1565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553310__FUN_00553310.c
1566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554510__FUN_00554510.c
1567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556040__FUN_00556040.c
1568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055687b__FUN_0055687b.c
1569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557410__FUN_00557410.c
1570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559330__FUN_00559330.c
1571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb20__FUN_0055bb20.c
1572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c2a0__FUN_0055c2a0.c
1573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055cf50__FUN_0055cf50.c
1574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055eba0__FUN_0055eba0.c
1575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560b30__FUN_00560b30.c
1576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561a15__FUN_00561a15.c
1577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562605__sub_562605.c
1578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563260__FUN_00563260.c
1579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564480__FUN_00564480.c
1580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564890__FUN_00564890.c
1581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005653f0__thunk_FUN_00565400.c
1582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005666b0__FUN_005666b0.c
1583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566e40__FUN_00566e40.c
1584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567980__FUN_00567980.c
1585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568210__FUN_00568210.c
1586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568f20__FUN_00568f20.c
1587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a240__FUN_0056a240.c
1588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d020__FUN_0056d020.c
1589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f80b__sub_56F80B.c
1590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a180__FUN_0057a180.c
1591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a690__FUN_0057a690.c
1592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a980__FUN_0057a980.c
1593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aec0__sub_57AEC0.c
1594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b7f0__FUN_0057b7f0.c
1595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057c950__FUN_0057c950.c
1596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e940__sub_57E940.c
1597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581070__FUN_00581070.c
1598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581ee0__FUN_00581ee0.c
1599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582eb0__FUN_00582eb0.c
1600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583690__FUN_00583690.c
1601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584f30__FUN_00584f30.c
1602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585810__FUN_00585810.c
1603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586070__FUN_00586070.c
1604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586a90__FUN_00586a90.c
1605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587100__FUN_00587100.c
1606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587510__FUN_00587510.c
1607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587aa0__FUN_00587aa0.c
1608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058801d__FUN_0058801d.c
1609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588821__FUN_00588821.c
1610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005894bd__FUN_005894bd.c
1611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589ca4__FUN_00589ca4.c
1612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a323__FUN_0058a323.c
1613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a8a3__FUN_0058a8a3.c
1614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b050___strrchr.c
1615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bc68__FUN_0058bc68.c
1616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c6f0____allmul.c
1617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dc29__sub_58DC29.c
1618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e12e__FUN_0058e12e.c
1619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fb7e__FUN_0058fb7e.c
1620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590616__FUN_00590616.c
1621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591ca1__FUN_00591ca1.c
1622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592a62__FUN_00592a62.c
1623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593bbd__FUN_00593bbd.c
1624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594e1a__FUN_00594e1a.c
1625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595621__FUN_00595621.c
1626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596245__FUN_00596245.c
1627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005972bd__FUN_005972bd.c
1628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059807b__FUN_0059807b.c
1629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059867e__send.c
1630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598775__FUN_00598775.c
1631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c4a__FUN_00598c4a.c
1632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005992b7__FUN_005992b7.c
1633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059977e__FUN_0059977e.c
1634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599897__sub_599897.c
1635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d17__FUN_00599d17.c
1636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a407__FUN_0059a407.c
1637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a86c__FUN_0059a86c.c
1638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ada3__FUN_0059ada3.c
1639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b3b0__FUN_0059b3b0.c
1640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bf19__FUN_0059bf19.c
1641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c48c__Unwind_0059c48c.c
1642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5bc__Unwind_0059c5bc.c
1643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c684__Unwind_0059c684.c
1644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7d0__Unwind_0059c7d0.c
1645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8b2__Unwind_0059c8b2.c
1646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca10__Unwind_0059ca10.c
1647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb80__Unwind_0059cb80.c
1648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cce0__Unwind_0059cce0.c
1649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce7e__Unwind_0059ce7e.c
1650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf86__Unwind_0059cf86.c
1651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d091__Unwind_0059d091.c
1652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1d8__Unwind_0059d1d8.c
1653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d384__Unwind_0059d384.c
1654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d524__Unwind_0059d524.c
1655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d99e__FUN_0059d99e.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_E.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
