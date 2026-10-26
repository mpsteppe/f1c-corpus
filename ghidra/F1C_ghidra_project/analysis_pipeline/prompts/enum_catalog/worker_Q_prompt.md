# WORKER Q — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker Q of 20, items 5297–5626.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_Q.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (330)

5297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004039c0__FUN_004039c0.c
5298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404b50__FUN_00404b50.c
5299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405410__FUN_00405410.c
5300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405f80__FUN_00405f80.c
5301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406b60__sub_406B60.c
5302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407e40__FUN_00407e40.c
5303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408490__FUN_00408490.c
5304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040aa20__FUN_0040aa20.c
5305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040bcd0__FUN_0040bcd0.c
5306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ca30__FUN_0040ca30.c
5307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d9fc__sub_40D9FC.c
5308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e770__FUN_0040e770.c
5309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f550__FUN_0040f550.c
5310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411440__FUN_00411440.c
5311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00412e50__FUN_00412e50.c
5312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144c0__FUN_004144c0.c
5313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415730__FUN_00415730.c
5314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418b90__FUN_00418b90.c
5315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a2b0__FUN_0041a2b0.c
5316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041c3e0__FUN_0041c3e0.c
5317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f1e0__FUN_0041f1e0.c
5318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421910__FUN_00421910.c
5319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423459__FUN_00423459.c
5320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424cd0__FUN_00424cd0.c
5321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a180__FUN_0042a180.c
5322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042aee0__FUN_0042aee0.c
5323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042cee0__FUN_0042cee0.c
5324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042eaa0__FUN_0042eaa0.c
5325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004319c0__FUN_004319c0.c
5326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004328f0__FUN_004328f0.c
5327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433d60__FUN_00433d60.c
5328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435260__FUN_00435260.c
5329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004380b0__FUN_004380b0.c
5330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043d8de__FUN_0043d8de.c
5331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004412f0__FUN_004412f0.c
5332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044657d__FUN_0044657d.c
5333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448330__FUN_00448330.c
5334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449000__FUN_00449000.c
5335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a4b0__FUN_0044a4b0.c
5336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c550__FUN_0044c550.c
5337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c950__FUN_0044c950.c
5338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc20__FUN_0044cc20.c
5339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce90__FUN_0044ce90.c
5340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d160__FUN_0044d160.c
5341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d4f0__FUN_0044d4f0.c
5342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d8b0__FUN_0044d8b0.c
5343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc70__FUN_0044dc70.c
5344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e030__FUN_0044e030.c
5345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3f0__FUN_0044e3f0.c
5346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e7b0__FUN_0044e7b0.c
5347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb70__FUN_0044eb70.c
5348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f460__FUN_0044f460.c
5349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00451720__FUN_00451720.c
5350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454d30__FUN_00454d30.c
5351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456170__FUN_00456170.c
5352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582c0__FUN_004582c0.c
5353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b300__FUN_0045b300.c
5354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bbe0__FUN_0045bbe0.c
5355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c320__FUN_0045c320.c
5356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d0d0__sub_45D0D0.c
5357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045f2a0__FUN_0045f2a0.c
5358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004615c0__FUN_004615c0.c
5359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462380__FUN_00462380.c
5360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004630c0__FUN_004630c0.c
5361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463f70__FUN_00463f70.c
5362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464bb0__FUN_00464bb0.c
5363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465fd0__FUN_00465fd0.c
5364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004669a0__FUN_004669a0.c
5365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00468a00__sub_468A00.c
5366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a9c0__FUN_0046a9c0.c
5367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cd20__sub_46CD20.c
5368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e5c0__FUN_0046e5c0.c
5369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fe50__FUN_0046fe50.c
5370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004713c0__FUN_004713c0.c
5371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004726c0__FUN_004726c0.c
5372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473e50__FUN_00473e50.c
5373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475140__FUN_00475140.c
5374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004765f0__sub_4765F0.c
5375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477810__FUN_00477810.c
5376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004782a0__FUN_004782a0.c
5377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004797c0__FUN_004797c0.c
5378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479d00__FUN_00479d00.c
5379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a640__FUN_0047a640.c
5380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bd90__FUN_0047bd90.c
5381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047dd10__sub_47DD10.c
5382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f3f0__FUN_0047f3f0.c
5383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485960__FUN_00485960.c
5384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486330__FUN_00486330.c
5385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486aa0__FUN_00486aa0.c
5386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048741b__sub_48741B.c
5387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487ed0__FUN_00487ed0.c
5388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488f40__FUN_00488f40.c
5389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489ab0__FUN_00489ab0.c
5390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b030__FUN_0048b030.c
5391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c9a0__FUN_0048c9a0.c
5392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3f0__FUN_0048d3f0.c
5393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e3a0__FUN_0048e3a0.c
5394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f330__FUN_0048f330.c
5395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048feb0__FUN_0048feb0.c
5396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490930__FUN_00490930.c
5397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491760__FUN_00491760.c
5398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491f60__FUN_00491f60.c
5399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494fa2__sub_494FA2.c
5400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004957a0__FUN_004957a0.c
5401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004966e0__FUN_004966e0.c
5402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004976c0__FUN_004976c0.c
5403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004981f0__FUN_004981f0.c
5404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d70__FUN_00498d70.c
5405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004992e0__FUN_004992e0.c
5406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a00__FUN_00499a00.c
5407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e10__FUN_00499e10.c
5408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a250__FUN_0049a250.c
5409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aa30__FUN_0049aa30.c
5410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b050__FUN_0049b050.c
5411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049c486__sub_49C486.c
5412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e3e0__FUN_0049e3e0.c
5413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ecc0__FUN_0049ecc0.c
5414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0248__sub_4A0248.c
5415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0de0__FUN_004a0de0.c
5416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b90__FUN_004a1b90.c
5417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a29a0__FUN_004a29a0.c
5418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4108__sub_4A4108.c
5419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5c40__FUN_004a5c40.c
5420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a70e0__FUN_004a70e0.c
5421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0540__FUN_004b0540.c
5422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b19d0__FUN_004b19d0.c
5423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2100__FUN_004b2100.c
5424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b29b0__FUN_004b29b0.c
5425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b31a0__FUN_004b31a0.c
5426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b41c0__FUN_004b41c0.c
5427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4b50__FUN_004b4b50.c
5428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5da0__FUN_004b5da0.c
5429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7300__FUN_004b7300.c
5430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8bd0__FUN_004b8bd0.c
5431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cb0__FUN_004b9cb0.c
5432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba740__FUN_004ba740.c
5433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004baeb0__FUN_004baeb0.c
5434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbec4__sub_4BBEC4.c
5435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7f0__thunk_FUN_004bd800.c
5436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be700__FUN_004be700.c
5437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c03a0__FUN_004c03a0.c
5438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1670__FUN_004c1670.c
5439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2bf0__FUN_004c2bf0.c
5440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c38d0__FUN_004c38d0.c
5441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c51a0__FUN_004c51a0.c
5442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6b60__FUN_004c6b60.c
5443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c70__FUN_004c7c70.c
5444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c85d0__FUN_004c85d0.c
5445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c91d0__FUN_004c91d0.c
5446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9c00__FUN_004c9c00.c
5447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cbc50__FUN_004cbc50.c
5448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce380__FUN_004ce380.c
5449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0cf0__sub_4D0CF0.c
5450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1d40__FUN_004d1d40.c
5451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47e0__FUN_004d47e0.c
5452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c60__sub_4D5C60.c
5453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7cc0__FUN_004d7cc0.c
5454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8760__FUN_004d8760.c
5455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9dd0__FUN_004d9dd0.c
5456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db110__sub_4DB110.c
5457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc1a0__FUN_004dc1a0.c
5458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd60__FUN_004dcd60.c
5459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4e0__FUN_004dd4e0.c
5460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfb90__FUN_004dfb90.c
5461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e1fd0__FUN_004e1fd0.c
5462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3890__FUN_004e3890.c
5463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e5080__FUN_004e5080.c
5464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9630__FUN_004e9630.c
5465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed220__FUN_004ed220.c
5466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef930__FUN_004ef930.c
5467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1630__FUN_004f1630.c
5468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f2b10__FUN_004f2b10.c
5469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6b90__FUN_004f6b90.c
5470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f89a0__FUN_004f89a0.c
5471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9190__FUN_004f9190.c
5472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb260__FUN_004fb260.c
5473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd840__FUN_004fd840.c
5474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500010__FUN_00500010.c
5475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500bc8__FUN_00500bc8.c
5476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502c28__FUN_00502c28.c
5477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005043c9__FUN_005043c9.c
5478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506ccc__FUN_00506ccc.c
5479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005082d1__FUN_005082d1.c
5480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509644__FUN_00509644.c
5481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a223__FUN_0050a223.c
5482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae5a__FUN_0050ae5a.c
5483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b409__FUN_0050b409.c
5484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b8a9__FUN_0050b8a9.c
5485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c5b0__FUN_0050c5b0.c
5486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ce79__sub_50CE79.c
5487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d96d__FUN_0050d96d.c
5488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e0d9__FUN_0050e0d9.c
5489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e887__FUN_0050e887.c
5490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fd16__FUN_0050fd16.c
5491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005115ee__FUN_005115ee.c
5492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512183__FUN_00512183.c
5493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513374__FUN_00513374.c
5494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513e80__FUN_00513e80.c
5495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515bb0__FUN_00515bb0.c
5496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516853__FUN_00516853.c
5497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517899__FUN_00517899.c
5498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051935c__FUN_0051935c.c
5499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a5ea__FUN_0051a5ea.c
5500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bf23__FUN_0051bf23.c
5501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cd53__FUN_0051cd53.c
5502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e1ef__FUN_0051e1ef.c
5503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f0be__sub_51F0BE.c
5504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051febe__sub_51FEBE.c
5505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052156f__FUN_0052156f.c
5506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522c2d__sub_522C2D.c
5507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052717c__sub_52717C.c
5508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529000__FUN_00529000.c
5509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d9f0__FUN_0052d9f0.c
5510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e530__FUN_0052e530.c
5511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ae6__AVIFileRelease.c
5512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535e10__FUN_00535e10.c
5513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537ec0__FUN_00537ec0.c
5514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053a020__FUN_0053a020.c
5515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b200__FUN_0053b200.c
5516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c210__FUN_0053c210.c
5517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cb90__FUN_0053cb90.c
5518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d4f0__FUN_0053d4f0.c
5519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540760__FUN_00540760.c
5520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541500__FUN_00541500.c
5521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542460__FUN_00542460.c
5522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005435d0__FUN_005435d0.c
5523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545020__FUN_00545020.c
5524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545930__FUN_00545930.c
5525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547040__FUN_00547040.c
5526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005478b0__FUN_005478b0.c
5527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548eb0__FUN_00548eb0.c
5528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a240__FUN_0054a240.c
5529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b4d0__FUN_0054b4d0.c
5530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c150__FUN_0054c150.c
5531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d910__FUN_0054d910.c
5532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f2f0__FUN_0054f2f0.c
5533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fd30__FUN_0054fd30.c
5534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005507e0__FUN_005507e0.c
5535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551810__FUN_00551810.c
5536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552f20__FUN_00552f20.c
5537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553db0__FUN_00553db0.c
5538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554d70__FUN_00554d70.c
5539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556730__FUN_00556730.c
5540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005570c0__FUN_005570c0.c
5541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558cf0__FUN_00558cf0.c
5542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559a70__FUN_00559a70.c
5543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055be80__FUN_0055be80.c
5544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c9c0__FUN_0055c9c0.c
5545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d560__FUN_0055d560.c
5546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560410__FUN_00560410.c
5547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560fe0__FUN_00560fe0.c
5548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561f60__FUN_00561f60.c
5549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563000__FUN_00563000.c
5550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563f70__sub_563F70.c
5551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564680__WSACleanup.c
5552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564b80__FUN_00564b80.c
5553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565f20__FUN_00565f20.c
5554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566c30__FUN_00566c30.c
5555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567700__FUN_00567700.c
5556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567cc0__FUN_00567cc0.c
5557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568be0__FUN_00568be0.c
5558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005698e0__FUN_005698e0.c
5559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c3a0__FUN_0056c3a0.c
5560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056ec00__FUN_0056ec00.c
5561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a000__FUN_0057a000.c
5562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a560__FUN_0057a560.c
5563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a8c0__FUN_0057a8c0.c
5564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057adc0__FUN_0057adc0.c
5565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b630__FUN_0057b630.c
5566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bca0__sub_57BCA0.c
5567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e3a0__FUN_0057e3a0.c
5568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057fbe0__FUN_0057fbe0.c
5569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005819c0__FUN_005819c0.c
5570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582720__FUN_00582720.c
5571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583430__FUN_00583430.c
5572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005840c6__sub_5840C6.c
5573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585400__FUN_00585400.c
5574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e60__FUN_00585e60.c
5575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586620__FUN_00586620.c
5576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f40__FUN_00586f40.c
5577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005873f0__FUN_005873f0.c
5578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587880__FUN_00587880.c
5579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587d33____fclose_lk.c
5580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058850f__FUN_0058850f.c
5581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588f8b__FUN_00588f8b.c
5582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589aa4__FUN_00589aa4.c
5583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a05a__FUN_0058a05a.c
5584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a677__FUN_0058a677.c
5585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ac95__FUN_0058ac95.c
5586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ba36__FUN_0058ba36.c
5587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c232__FUN_0058c232.c
5588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d82c__FUN_0058d82c.c
5589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058de2c__FUN_0058de2c.c
5590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f014__FUN_0058f014.c
5591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590303__FUN_00590303.c
5592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059136e__sub_59136E.c
5593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005921c5__FUN_005921c5.c
5594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593694__FUN_00593694.c
5595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594529__FUN_00594529.c
5596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595310__FUN_00595310.c
5597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595dc8__FUN_00595dc8.c
5598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596dfe__FUN_00596dfe.c
5599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059797b__FUN_0059797b.c
5600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059864e__recvfrom.c
5601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986f8__sub_5986F8.c
5602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005989d7__FUN_005989d7.c
5603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598fd4__FUN_00598fd4.c
5604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599534__FUN_00599534.c
5605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599822__FUN_00599822.c
5606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599958__FUN_00599958.c
5607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a2fe__sub_59A2FE.c
5608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a6fe__sub_59A6FE.c
5609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ab83__FUN_0059ab83.c
5610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b086__FUN_0059b086.c
5611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bb00__FUN_0059bb00.c
5612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c414__Unwind_0059c414.c
5613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c53e__Unwind_0059c53e.c
5614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c634__Unwind_0059c634.c
5615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6fc__Unwind_0059c6fc.c
5616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c854__Unwind_0059c854.c
5617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c964__Unwind_0059c964.c
5618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb00__Unwind_0059cb00.c
5619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc60__Unwind_0059cc60.c
5620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cda0__Unwind_0059cda0.c
5621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf0b__Unwind_0059cf0b.c
5622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d02e__Unwind_0059d02e.c
5623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d150__Unwind_0059d150.c
5624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2e4__Unwind_0059d2e4.c
5625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d498__Unwind_0059d498.c
5626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d7b5__FUN_0059d7b5.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_Q.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
