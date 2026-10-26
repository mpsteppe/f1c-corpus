# WORKER P — F1C Cross-Validation Round 2

You are auditing ALL documented function entries across all docs/ files.
Round 2 uses updated docs/12 (2,356 globals) and docs/13 (6,910 lines) as ground truth.
Worker P of 20, items 5260–5609.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — global names
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct fields
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json` — call edges

## OUTPUT FILE
**APPEND** to (do NOT overwrite): %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_P.md

The file already contains completed verdicts. Before processing each function, check if `## FUN_XXXXXXXX` already appears in the output file — if so, skip it entirely.

## YOUR REMAINING FUNCTIONS (224)

5279. FUN_004B9870
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9870__FUN_004b9870.c

5280. FUN_0052D9D0
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d9d0__FUN_0052d9d0.c

5281. FUN_0055CE50
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ce50__FUN_0055ce50.c

5292. FUN_0059D5A8
   doc: docs/01-engine-architecture.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5a8__Unwind_0059d5a8.c

5327. FUN_004D98A0
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d98a0__FUN_004d98a0.c

5328. FUN_00594F3E
   doc: docs/06-session-race-logic.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594f3e__FUN_00594f3e.c

5392. FUN_004DE610
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de610__FUN_004de610.c

5393. FUN_00462CE0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462ce0__FUN_00462ce0.c

5394. FUN_00462940
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462940__FUN_00462940.c

5395. FUN_0044DB20
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db20__FUN_0044db20.c

5396. FUN_0044D1F0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d1f0__FUN_0044d1f0.c

5397. FUN_0044EB40
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb40__FUN_0044eb40.c

5398. FUN_0044CF20
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf20__FUN_0044cf20.c

5399. FUN_0044E2D0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2d0__FUN_0044e2d0.c

5400. FUN_0044D640
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d640__FUN_0044d640.c

5401. FUN_0044D0A0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d0a0__FUN_0044d0a0.c

5402. FUN_0044E450
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e450__FUN_0044e450.c

5403. FUN_0044E6C0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e6c0__FUN_0044e6c0.c

5404. FUN_0044D670
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d670__FUN_0044d670.c

5405. FUN_0044D8E0
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d8e0__FUN_0044d8e0.c

5406. FUN_0045CA20
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ca20__FUN_0045ca20.c

5407. FUN_0044D730
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d730__FUN_0044d730.c

5408. FUN_00491280
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491280__FUN_00491280.c

5409. FUN_0046C710
   doc: docs/17-physics-collision.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c710__FUN_0046c710.c

5410. FUN_0056E970
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056e970__FUN_0056e970.c

5411. FUN_004E94A3
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e94a3__FUN_004e94a3.c

5412. FUN_004423B0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004423b0__FUN_004423b0.c

5413. FUN_00441BB0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441bb0__FUN_00441bb0.c

5414. FUN_00438C10
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438c10__FUN_00438c10.c

5415. FUN_00567030
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567030__FUN_00567030.c

5416. FUN_00447270
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447270__FUN_00447270.c

5417. FUN_00449A20
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449a20__FUN_00449a20.c

5418. FUN_00434420
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434420__FUN_00434420.c

5419. FUN_00566EE0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566ee0__FUN_00566ee0.c

5420. FUN_00447AB0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447ab0__FUN_00447ab0.c

5421. FUN_004FB260
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb260__FUN_004fb260.c

5422. FUN_00569860
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569860__FUN_00569860.c

5423. FUN_004EE2D0
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c

5424. FUN_0044CD54
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd54__sub_44CD54.c

5425. FUN_00540CA1
   doc: docs/18-physics-dynamics.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540ca1__sub_540CA1.c

5426. FUN_004C7F30
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7f30__FUN_004c7f30.c

5427. FUN_00414D70
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414d70__FUN_00414d70.c

5428. FUN_00487960
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487960__FUN_00487960.c

5429. FUN_0048B600
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b600__FUN_0048b600.c

5430. FUN_00497D20
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497d20__FUN_00497d20.c

5431. FUN_0047B730
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b730__FUN_0047b730.c

5432. FUN_00557120
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557120__FUN_00557120.c

5433. FUN_0049B370
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b370__FUN_0049b370.c

5434. FUN_00504508
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504508__FUN_00504508.c

5435. FUN_00475A90
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475a90__FUN_00475a90.c

5436. FUN_0053EB70
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053eb70__FUN_0053eb70.c

5437. FUN_005058D2
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005058d2__FUN_005058d2.c

5438. FUN_00493E20
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00493e20__FUN_00493e20.c

5439. FUN_005038C0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005038c0__FUN_005038c0.c

5440. FUN_00503920
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503920__FUN_00503920.c

5441. FUN_0051030D
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051030d__FUN_0051030d.c

5442. FUN_0050B399
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b399__FUN_0050b399.c

5443. FUN_004CEF30
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cef30__FUN_004cef30.c

5444. FUN_00494470
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494470__FUN_00494470.c

5445. FUN_004662E0
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004662e0__FUN_004662e0.c

5446. FUN_004C9360
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9360__FUN_004c9360.c

5447. FUN_0044F540
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f540__FUN_0044f540.c

5448. FUN_0044CAB4
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cab4__sub_44CAB4.c

5449. FUN_0049AB60
   doc: docs/19-renderer.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ab60__sub_49AB60.c

5450. FUN_004144C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144c0__FUN_004144c0.c

5451. FUN_0059B650
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b650__FUN_0059b650.c

5452. FUN_00593E1B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593e1b__FUN_00593e1b.c

5453. FUN_00585130
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585130__FUN_00585130.c

5454. FUN_0058DD89
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd89__FUN_0058dd89.c

5455. FUN_00553FC0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553fc0__FUN_00553fc0.c

5456. FUN_0056C020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c020__FUN_0056c020.c

5457. FUN_005531F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005531f0__FUN_005531f0.c

5458. FUN_00589057
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589057__FUN_00589057.c

5459. FUN_005870D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005870d0__FUN_005870d0.c

5460. FUN_00466980
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466980__FUN_00466980.c

5461. FUN_00535560
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535560__FUN_00535560.c

5462. FUN_0055EF88
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ef88__FUN_0055ef88.c

5463. FUN_00456280
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456280__FUN_00456280.c

5464. FUN_0047C7F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c7f0__FUN_0047c7f0.c

5465. FUN_00497240
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497240__FUN_00497240.c

5466. FUN_004BB650
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb650__FUN_004bb650.c

5467. FUN_005038EF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005038ef__FUN_005038ef.c

5468. FUN_0053D410
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d410__FUN_0053d410.c

5469. FUN_00597037
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597037__FUN_00597037.c

5470. FUN_004045F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004045f0__FUN_004045f0.c

5471. FUN_00463140
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463140__FUN_00463140.c

5472. FUN_00488970
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488970__FUN_00488970.c

5473. FUN_004B20D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b20d0__FUN_004b20d0.c

5474. FUN_004DC310
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc310__FUN_004dc310.c

5475. FUN_0051DFCB
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dfcb__FUN_0051dfcb.c

5476. FUN_00582FD0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582fd0__FUN_00582fd0.c

5477. FUN_00405160
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405160__FUN_00405160.c

5478. FUN_00495920
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495920__FUN_00495920.c

5479. FUN_00512144
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512144__FUN_00512144.c

5480. FUN_00599485
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599485__FUN_00599485.c

5481. FUN_0040B6F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b6f0__FUN_0040b6f0.c

5482. FUN_004670E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004670e0__FUN_004670e0.c

5483. FUN_0048D6F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d6f0__FUN_0048d6f0.c

5484. FUN_004B1375
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1375__FUN_004b1375.c

5485. FUN_004D8840
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8840__FUN_004d8840.c

5486. FUN_00513D3D
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513d3d__FUN_00513d3d.c

5487. FUN_00586ED0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586ed0__FUN_00586ed0.c

5488. FUN_004734A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004734a0__FUN_004734a0.c

5489. FUN_00418D60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418d60__FUN_00418d60.c

5490. FUN_0048C9F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c9f0__FUN_0048c9f0.c

5491. FUN_004A57F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a57f0__FUN_004a57f0.c

5492. FUN_004D7C10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7c10__FUN_004d7c10.c

5493. FUN_00511060
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511060__FUN_00511060.c

5494. FUN_0054A730
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a730__FUN_0054a730.c

5495. FUN_00564AB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564ab0__FUN_00564ab0.c

5496. FUN_0041FDF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fdf0__FUN_0041fdf0.c

5497. FUN_00477080
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477080__FUN_00477080.c

5498. FUN_00497510
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497510__FUN_00497510.c

5499. FUN_004BBED0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbed0__FUN_004bbed0.c

5500. FUN_0050ED19
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ed19__FUN_0050ed19.c

5501. FUN_005836E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005836e0__FUN_005836e0.c

5502. FUN_0059C5E4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5e4__Unwind_0059c5e4.c

5503. FUN_00414140
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414140__FUN_00414140.c

5504. FUN_004717E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004717e0__FUN_004717e0.c

5505. FUN_00491DB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491db0__FUN_00491db0.c

5506. FUN_004B4F50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4f50__FUN_004b4f50.c

5507. FUN_004DFB00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfb00__FUN_004dfb00.c

5508. FUN_005198B3
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005198b3__FUN_005198b3.c

5509. FUN_005631A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005631a0__FUN_005631a0.c

5510. FUN_00567900
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567900__FUN_00567900.c

5511. FUN_004988A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988a0__FUN_004988a0.c

5512. FUN_0054FE10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fe10__FUN_0054fe10.c

5513. FUN_00405670
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405670__FUN_00405670.c

5514. FUN_00462380
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462380__FUN_00462380.c

5515. FUN_00487D50
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487d50__FUN_00487d50.c

5516. FUN_004A0DB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0db0__FUN_004a0db0.c

5517. FUN_004CE8F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce8f0__FUN_004ce8f0.c

5518. FUN_0050CDEC
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cdec__FUN_0050cdec.c

5519. FUN_00546F30
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546f30__FUN_00546f30.c

5520. FUN_0059B24A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b24a__RtlUnwind.c

5521. FUN_00567980
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567980__FUN_00567980.c

5522. FUN_0053C190
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c190__FUN_0053c190.c

5523. FUN_0050B409
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b409__FUN_0050b409.c

5524. FUN_004BDF90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdf90__FUN_004bdf90.c

5525. FUN_0049ADB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049adb0__FUN_0049adb0.c

5526. FUN_004856C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004856c0__FUN_004856c0.c

5527. FUN_0045C030
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c030__FUN_0045c030.c

5528. FUN_004C5DE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5de0__FUN_004c5de0.c

5529. FUN_0050B42A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b42a__FUN_0050b42a.c

5530. FUN_00546FE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546fe0__FUN_00546fe0.c

5531. FUN_0059163B
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059163b__FUN_0059163b.c

5532. FUN_0059A418
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a418__Gninc.c

5533. FUN_00410B60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b60__FUN_00410b60.c

5534. FUN_00471B20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471b20__FUN_00471b20.c

5535. FUN_00491EE0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491ee0__FUN_00491ee0.c

5536. FUN_004B52A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b52a0__FUN_004b52a0.c

5537. FUN_004E0D70
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0d70__FUN_004e0d70.c

5538. FUN_0051AD93
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ad93__FUN_0051ad93.c

5539. FUN_005676C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005676c0__FUN_005676c0.c

5540. FUN_0058A935
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a935___malloc.c

5541. FUN_0041ED20
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ed20__FUN_0041ed20.c

5542. FUN_00475570
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475570__FUN_00475570.c

5543. FUN_004963C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004963c0__FUN_004963c0.c

5544. FUN_004BA820
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba820__FUN_004ba820.c

5545. FUN_004F6B80
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6b80__FUN_004f6b80.c

5546. FUN_0052803A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052803a__FUN_0052803a.c

5547. FUN_0057A160
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a160__FUN_0057a160.c

5548. FUN_005830C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005830c0__FUN_005830c0.c

5549. FUN_0042E1F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e1f0__FUN_0042e1f0.c

5550. FUN_00479A10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479a10__FUN_00479a10.c

5551. FUN_004992E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004992e0__FUN_004992e0.c

5552. FUN_004C2780
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2780__FUN_004c2780.c

5553. FUN_005006A4
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006a4__FUN_005006a4.c

5554. FUN_0053C2A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c2a0__FUN_0053c2a0.c

5555. FUN_0058AC7A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ac7a__FUN_0058ac7a.c

5556. FUN_00406F90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406f90__FUN_00406f90.c

5557. FUN_004795E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004795e0__FUN_004795e0.c

5558. FUN_00498D90
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d90__FUN_00498d90.c

5559. FUN_004BC390
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc390__FUN_004bc390.c

5560. FUN_005006D5
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006d5__FUN_005006d5.c

5561. FUN_0053B1D0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b1d0__FUN_0053b1d0.c

5562. FUN_00595621
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595621__FUN_00595621.c

5563. FUN_0040E1C0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1c0__FUN_0040e1c0.c

5564. FUN_004B1AB0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1ab0__FUN_004b1ab0.c

5565. FUN_00529000
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529000__FUN_00529000.c

5566. FUN_0059DA3A
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059da3a__FUN_0059da3a.c

5567. FUN_0049A490
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a490__FUN_0049a490.c

5568. FUN_0059DAB7
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059dab7__FUN_0059dab7.c

5569. FUN_004234A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004234a0__FUN_004234a0.c

5570. FUN_0047A5E0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a5e0__FUN_0047a5e0.c

5571. FUN_00499B10
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b10__FUN_00499b10.c

5572. FUN_004C3050
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3050__FUN_004c3050.c

5573. FUN_00503772
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503772__FUN_00503772.c

5574. FUN_0053C590
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c590__FUN_0053c590.c

5575. FUN_0058B9FF
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b9ff__FUN_0058b9ff.c

5576. FUN_00406020
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406020__FUN_00406020.c

5577. FUN_00462FF0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462ff0__FUN_00462ff0.c

5578. FUN_004883A0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004883a0__FUN_004883a0.c

5579. FUN_004A1A00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1a00__FUN_004a1a00.c

5580. FUN_004D0B00
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0b00__FUN_004d0b00.c

5581. FUN_0050D728
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d728__FUN_0050d728.c

5582. FUN_00547280
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547280__FUN_00547280.c

5583. FUN_0059DB88
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059db88__FUN_0059db88.c

5584. FUN_004685B0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004685b0__FUN_004685b0.c

5585. FUN_00495B60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b60__FUN_00495b60.c

5586. FUN_0059C5B2
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5b2__Unwind_0059c5b2.c

5587. FUN_0059D45C
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d45c__Unwind_0059d45c.c

5588. FUN_0059CB60
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb60__Unwind_0059cb60.c

5589. FUN_0050CBA3
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cba3__FUN_0050cba3.c

5590. FUN_0059CF03
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf03__Unwind_0059cf03.c

5591. FUN_0059CFDA
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfda__Unwind_0059cfda.c

5592. FUN_0058B59F
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b59f__FUN_0058b59f.c

5593. FUN_0059136E
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059136e__sub_59136E.c

5594. FUN_005381F0
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005381f0__sub_5381F0.c

5595. FUN_00564600
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564600__sub_564600.c

5596. FUN_0051F7CE
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f7ce__sub_51F7CE.c

5597. FUN_00441650
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441650__FUN_00441650.c

5598. FUN_00433370
   doc: docs/20-math-utilities.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433370__FUN_00433370.c

5599. FUN_00581070
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581070__FUN_00581070.c

5600. FUN_0059A5E9
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a5e9__FUN_0059a5e9.c

5601. FUN_0051868C
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051868c__FUN_0051868c.c

5602. FUN_00537D10
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537d10__FUN_00537d10.c

5603. FUN_0057AFA0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057afa0__FUN_0057afa0.c

5604. FUN_0057E8D0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e8d0__FUN_0057e8d0.c

5605. FUN_00598660
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598660__gethostbyname.c

5606. FUN_00564271
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564271__FUN_00564271.c

5607. FUN_005631D0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005631d0__FUN_005631d0.c

5608. FUN_0057BCA0
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bca0__sub_57BCA0.c

5609. FUN_0044CF94
   doc: docs/21-audio-network-internals.md
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf94__sub_44CF94.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate_2\worker_P.md.
1. Check EVERY function — no skipping.
2. Only flag REAL errors, not style differences.
3. FAIL entries must include all error tags AND a full corrected entry.
