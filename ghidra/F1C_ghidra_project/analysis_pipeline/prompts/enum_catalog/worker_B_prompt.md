# WORKER B — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker B of 20, items 332–662.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_B.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401030__FUN_00401030.c
333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404030__FUN_00404030.c
334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d40__FUN_00404d40.c
335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405670__FUN_00405670.c
336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406130__FUN_00406130.c
337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406f90__FUN_00406f90.c
338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408000__FUN_00408000.c
339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004085c0__sub_4085C0.c
340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040acd0__FUN_0040acd0.c
341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c070__FUN_0040c070.c
342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d0b0__FUN_0040d0b0.c
343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dc00__FUN_0040dc00.c
344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e990__FUN_0040e990.c
345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040fda0__FUN_0040fda0.c
346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004116c0__FUN_004116c0.c
347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00413820__FUN_00413820.c
348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004149a0__FUN_004149a0.c
349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415c40__FUN_00415c40.c
350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418dd0__FUN_00418dd0.c
351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a8c0__FUN_0041a8c0.c
352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041e890__FUN_0041e890.c
353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fdf0__FUN_0041fdf0.c
354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004219b0__FUN_004219b0.c
355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004236f0__FUN_004236f0.c
356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004258c0__FUN_004258c0.c
357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a7d0__FUN_0042a7d0.c
358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042b8b0__FUN_0042b8b0.c
359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dc80__FUN_0042dc80.c
360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ecc0__FUN_0042ecc0.c
361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431bd0__FUN_00431bd0.c
362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432a10__FUN_00432a10.c
363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434000__FUN_00434000.c
364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004353f0__FUN_004353f0.c
365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438930__FUN_00438930.c
366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e5d0__FUN_0043e5d0.c
367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441650__FUN_00441650.c
368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447270__FUN_00447270.c
369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448570__FUN_00448570.c
370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004493a0__FUN_004493a0.c
371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044acb0__FUN_0044acb0.c
372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c680__FUN_0044c680.c
373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ca10__FUN_0044ca10.c
374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ccb0__FUN_0044ccb0.c
375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf34__sub_44CF34.c
376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d250__FUN_0044d250.c
377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d5e0__FUN_0044d5e0.c
378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d9a0__FUN_0044d9a0.c
379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd60__FUN_0044dd60.c
380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e120__FUN_0044e120.c
381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e4e0__FUN_0044e4e0.c
382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e8a0__FUN_0044e8a0.c
383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec60__FUN_0044ec60.c
384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f640__FUN_0044f640.c
385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004527c0__FUN_004527c0.c
386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455b30__FUN_00455b30.c
387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456f70__FUN_00456f70.c
388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00458df0__FUN_00458df0.c
389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b430__FUN_0045b430.c
390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bde0__FUN_0045bde0.c
391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c750__FUN_0045c750.c
392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d4c0__FUN_0045d4c0.c
393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460710__FUN_00460710.c
394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461c70__FUN_00461c70.c
395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004624e0__FUN_004624e0.c
396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004636e6__sub_4636E6.c
397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004646f0__FUN_004646f0.c
398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464ee0__FUN_00464ee0.c
399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466090__FUN_00466090.c
400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004670e0__FUN_004670e0.c
401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469857__FUN_00469857.c
402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b310__FUN_0046b310.c
403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d5f0__FUN_0046d5f0.c
404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ec10__sub_46EC10.c
405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470230__FUN_00470230.c
406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471650__FUN_00471650.c
407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472cc0__FUN_00472cc0.c
408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474440__FUN_00474440.c
409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475c80__FUN_00475c80.c
410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004767c0__sub_4767C0.c
411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477ea0__FUN_00477ea0.c
412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478690__FUN_00478690.c
413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004798b0__FUN_004798b0.c
414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479eb0__FUN_00479eb0.c
415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047aa80__FUN_0047aa80.c
416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c0a0__FUN_0047c0a0.c
417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047eb30__FUN_0047eb30.c
418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485540__FUN_00485540.c
419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485b20__FUN_00485b20.c
420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486480__FUN_00486480.c
421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486f00__FUN_00486f00.c
422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487640__FUN_00487640.c
423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004881b0__FUN_004881b0.c
424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489450__FUN_00489450.c
425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489e90__FUN_00489e90.c
426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b600__FUN_0048b600.c
427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ca26__sub_48CA26.c
428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d6a0__FUN_0048d6a0.c
429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e670__FUN_0048e670.c
430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f9f0__FUN_0048f9f0.c
431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490190__FUN_00490190.c
432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490d00__FUN_00490d00.c
433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004919c0__FUN_004919c0.c
434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494600__FUN_00494600.c
435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495020__FUN_00495020.c
436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495930__FUN_00495930.c
437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496e20__FUN_00496e20.c
438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497980__FUN_00497980.c
439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004985d0__FUN_004985d0.c
440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498e50__FUN_00498e50.c
441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499560__FUN_00499560.c
442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ab0__FUN_00499ab0.c
443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e60__FUN_00499e60.c
444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2e0__FUN_0049a2e0.c
445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ab60__sub_49AB60.c
446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b630__FUN_0049b630.c
447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049cfc0__FUN_0049cfc0.c
448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e570__FUN_0049e570.c
449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f070__FUN_0049f070.c
450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a06e0__FUN_004a06e0.c
451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0fb0__FUN_004a0fb0.c
452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1e20__FUN_004a1e20.c
453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a34a0__FUN_004a34a0.c
454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a48c0__FUN_004a48c0.c
455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5e60__FUN_004a5e60.c
456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004aa170__FUN_004aa170.c
457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0b20__FUN_004b0b20.c
458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a70__FUN_004b1a70.c
459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b21d0__FUN_004b21d0.c
460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a80__FUN_004b2a80.c
461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3ad0__FUN_004b3ad0.c
462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b43e0__FUN_004b43e0.c
463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5040__FUN_004b5040.c
464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6190__FUN_004b6190.c
465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8010__FUN_004b8010.c
466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9780__FUN_004b9780.c
467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d00__FUN_004b9d00.c
468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba820__FUN_004ba820.c
469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb200__FUN_004bb200.c
470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc060__FUN_004bc060.c
471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd970__FUN_004bd970.c
472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bef60__FUN_004bef60.c
473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0a20__FUN_004c0a20.c
474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1e40__FUN_004c1e40.c
475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c40__FUN_004c2c40.c
476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4240__FUN_004c4240.c
477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5bb0__FUN_004c5bb0.c
478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c73f0__FUN_004c73f0.c
479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7e80__FUN_004c7e80.c
480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8900__FUN_004c8900.c
481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9360__FUN_004c9360.c
482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9d60__FUN_004c9d60.c
483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc700__FUN_004cc700.c
484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce8f0__FUN_004ce8f0.c
485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1030__FUN_004d1030.c
486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2260__FUN_004d2260.c
487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d48b0__FUN_004d48b0.c
488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d68a0__FUN_004d68a0.c
489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7de0__FUN_004d7de0.c
490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d88d0__FUN_004d88d0.c
491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004da840__FUN_004da840.c
492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db520__FUN_004db520.c
493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc2e0__FUN_004dc2e0.c
494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf20__FUN_004dcf20.c
495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd9f0__FUN_004dd9f0.c
496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0c90__FUN_004e0c90.c
497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2370__FUN_004e2370.c
498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3a50__FUN_004e3a50.c
499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e5ae0__FUN_004e5ae0.c
500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9ca0__FUN_004e9ca0.c
501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed750__FUN_004ed750.c
502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efbd0__FUN_004efbd0.c
503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1890__FUN_004f1890.c
504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f3490__FUN_004f3490.c
505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6f20__FUN_004f6f20.c
506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c00__FUN_004f8c00.c
507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9420__FUN_004f9420.c
508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb8f0__FUN_004fb8f0.c
509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004feaa0__FUN_004feaa0.c
510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500190__FUN_00500190.c
511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005016e0__FUN_005016e0.c
512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503659__FUN_00503659.c
513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504b37__FUN_00504b37.c
514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507496__FUN_00507496.c
515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005087a2__FUN_005087a2.c
516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509959__FUN_00509959.c
517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a55b__FUN_0050a55b.c
518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050af57__sub_50AF57.c
519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b47e__FUN_0050b47e.c
520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c0a6__FUN_0050c0a6.c
521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c665__sub_50C665.c
522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d47d__sub_50D47D.c
523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dc90__FUN_0050dc90.c
524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e2ab__FUN_0050e2ab.c
525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050edd2__FUN_0050edd2.c
526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510012__FUN_00510012.c
527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051176b__sub_51176B.c
528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512334__FUN_00512334.c
529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b36__FUN_00513b36.c
530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051512c__FUN_0051512c.c
531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515ebc__sub_515EBC.c
532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516990__FUN_00516990.c
533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ac5__FUN_00517ac5.c
534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519622__FUN_00519622.c
535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ad93__FUN_0051ad93.c
536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c099__FUN_0051c099.c
537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d1db__FUN_0051d1db.c
538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e65f__FUN_0051e65f.c
539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f400__sub_51F400.c
540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052035e__sub_52035E.c
541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521895__FUN_00521895.c
542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052466c__FUN_0052466c.c
543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052765a__FUN_0052765a.c
544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052a090__FUN_0052a090.c
545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052de00__FUN_0052de00.c
546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e5d0__FUN_0052e5d0.c
547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ee0__FUN_00534ee0.c
548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536300__sub_536300.c
549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005385e0__FUN_005385e0.c
550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ab80__FUN_0053ab80.c
551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b490__FUN_0053b490.c
552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c590__FUN_0053c590.c
553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d130__FUN_0053d130.c
554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d930__FUN_0053d930.c
555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540da0__FUN_00540da0.c
556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005418e0__FUN_005418e0.c
557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542540__FUN_00542540.c
558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543920__FUN_00543920.c
559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545250__FUN_00545250.c
560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545d00__FUN_00545d00.c
561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005471d0__FUN_005471d0.c
562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005487a0__FUN_005487a0.c
563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549170__FUN_00549170.c
564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a5b0__FUN_0054a5b0.c
565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b9e0__FUN_0054b9e0.c
566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c230__FUN_0054c230.c
567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e100__FUN_0054e100.c
568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fa00__FUN_0054fa00.c
569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fe00__FUN_0054fe00.c
570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550ac0__FUN_00550ac0.c
571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551ce0__FUN_00551ce0.c
572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553070__FUN_00553070.c
573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554260__FUN_00554260.c
574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005550a0__FUN_005550a0.c
575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567e1__FUN_005567e1.c
576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557350__FUN_00557350.c
577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558e70__FUN_00558e70.c
578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559f00__FUN_00559f00.c
579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c040__FUN_0055c040.c
580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ce50__FUN_0055ce50.c
581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055da50__FUN_0055da50.c
582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005608f6__FUN_005608f6.c
583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561970__FUN_00561970.c
584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005622b0__FUN_005622b0.c
585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005631c4__sub_5631C4.c
586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005642b0__FUN_005642b0.c
587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005647d0__FUN_005647d0.c
588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565080__FUN_00565080.c
589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005664a0__FUN_005664a0.c
590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566db0__FUN_00566db0.c
591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567900__FUN_00567900.c
592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567f40__FUN_00567f40.c
593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568e30__FUN_00568e30.c
594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569c10__FUN_00569c10.c
595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056cd70__FUN_0056cd70.c
596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f060__FUN_0056f060.c
597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a0e6__sub_57A0E6.c
598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a610__FUN_0057a610.c
599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a920__FUN_0057a920.c
600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae70__FUN_0057ae70.c
601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b780__FUN_0057b780.c
602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057c7b0__FUN_0057c7b0.c
603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e7e0__FUN_0057e7e0.c
604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005805c0__FUN_005805c0.c
605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581c20__FUN_00581c20.c
606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582ba0__FUN_00582ba0.c
607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583650__FUN_00583650.c
608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584cd0__FUN_00584cd0.c
609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585680__FUN_00585680.c
610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585f90__FUN_00585f90.c
611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586a00__FUN_00586a00.c
612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587090__FUN_00587090.c
613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587490__FUN_00587490.c
614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587a50__FUN_00587a50.c
615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587f59__FUN_00587f59.c
616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005886a7__FUN_005886a7.c
617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589278__FUN_00589278.c
618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589c1b__FUN_00589c1b.c
619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2a6____amsg_exit.c
620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a7ec____setjmp3.c
621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058afcf__FUN_0058afcf.c
622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bbd2__FUN_0058bbd2.c
623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c43c__FUN_0058c43c.c
624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058da35__sub_58DA35.c
625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e060__FUN_0058e060.c
626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f7c9__FUN_0058f7c9.c
627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059045f__FUN_0059045f.c
628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005919da__FUN_005919da.c
629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592787__FUN_00592787.c
630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593981__FUN_00593981.c
631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594b76__FUN_00594b76.c
632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595550__FUN_00595550.c
633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596089__FUN_00596089.c
634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059706a__FUN_0059706a.c
635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597f6d____mbsnbicoll.c
636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059866c__htons.c
637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598750__FUN_00598750.c
638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598b5d__FUN_00598b5d.c
639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059925d__sub_59925D.c
640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599689__Catch_00599689.c
641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599868__sub_599868.c
642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599bf0__FUN_00599bf0.c
643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a38d__FUN_0059a38d.c
644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a7de__FUN_0059a7de.c
645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac7f__FUN_0059ac7f.c
646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b250__Direct3DCreate8.c
647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bde9__FUN_0059bde9.c
648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c464__Unwind_0059c464.c
649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c596__Unwind_0059c596.c
650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c666__Unwind_0059c666.c
651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c770__Unwind_0059c770.c
652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c88e__Unwind_0059c88e.c
653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9ab__Unwind_0059c9ab.c
654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb48__Unwind_0059cb48.c
655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc9e__Unwind_0059cc9e.c
656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce40__Unwind_0059ce40.c
657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf4b__Unwind_0059cf4b.c
658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d070__Unwind_0059d070.c
659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1a8__Unwind_0059d1a8.c
660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d348__Unwind_0059d348.c
661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4f4__Unwind_0059d4f4.c
662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d948__FUN_0059d948.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_B.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
