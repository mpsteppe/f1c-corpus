# WORKER N — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker N of 20, items 4304–4634.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_N.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

4304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403540__FUN_00403540.c
4305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004049d0__FUN_004049d0.c
4306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405050__FUN_00405050.c
4307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b90__FUN_00405b90.c
4308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406a90__FUN_00406a90.c
4309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407d40__FUN_00407d40.c
4310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004083e0__FUN_004083e0.c
4311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a680__sub_40A680.c
4312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b6c0__FUN_0040b6c0.c
4313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c890__FUN_0040c890.c
4314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d470__FUN_0040d470.c
4315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e6a0__FUN_0040e6a0.c
4316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f300__FUN_0040f300.c
4317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410f60__FUN_00410f60.c
4318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004122c0__FUN_004122c0.c
4319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414420__FUN_00414420.c
4320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415680__FUN_00415680.c
4321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418a60__FUN_00418a60.c
4322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a160__FUN_0041a160.c
4323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041be60__FUN_0041be60.c
4324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f150__FUN_0041f150.c
4325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421890__FUN_00421890.c
4326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00422fd0__FUN_00422fd0.c
4327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424ac0__FUN_00424ac0.c
4328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429fc2__sub_429FC2.c
4329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ae60__FUN_0042ae60.c
4330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ce00__FUN_0042ce00.c
4331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e400__FUN_0042e400.c
4332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431820__FUN_00431820.c
4333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432870__FUN_00432870.c
4334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433870__FUN_00433870.c
4335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434d40__FUN_00434d40.c
4336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00436610__FUN_00436610.c
4337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043bb80__FUN_0043bb80.c
4338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043f7f0__FUN_0043f7f0.c
4339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00443c07__FUN_00443c07.c
4340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448120__FUN_00448120.c
4341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448ee0__FUN_00448ee0.c
4342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a2d0__FUN_0044a2d0.c
4343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c430__FUN_0044c430.c
4344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c8c0__FUN_0044c8c0.c
4345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cbc0__FUN_0044cbc0.c
4346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce30__FUN_0044ce30.c
4347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d0d0__FUN_0044d0d0.c
4348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d460__FUN_0044d460.c
4349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d820__FUN_0044d820.c
4350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dbe0__FUN_0044dbe0.c
4351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dfa0__FUN_0044dfa0.c
4352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e360__FUN_0044e360.c
4353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e720__FUN_0044e720.c
4354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eae0__FUN_0044eae0.c
4355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f0a0__FUN_0044f0a0.c
4356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fcc0__FUN_0044fcc0.c
4357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454250__FUN_00454250.c
4358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456110__FUN_00456110.c
4359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457f90__FUN_00457f90.c
4360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ae00__FUN_0045ae00.c
4361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb50__thunk_FUN_0045b400.c
4362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c030__FUN_0045c030.c
4363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ce30__FUN_0045ce30.c
4364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045eb00__FUN_0045eb00.c
4365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461530__FUN_00461530.c
4366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462310__FUN_00462310.c
4367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462d30__FUN_00462d30.c
4368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463dc0__FUN_00463dc0.c
4369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464ae0__FUN_00464ae0.c
4370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465c30__FUN_00465c30.c
4371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004668e0__FUN_004668e0.c
4372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004685b0__FUN_004685b0.c
4373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a950__FUN_0046a950.c
4374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c8b0__FUN_0046c8b0.c
4375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e170__FUN_0046e170.c
4376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fdc0__FUN_0046fdc0.c
4377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470d30__FUN_00470d30.c
4378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472400__FUN_00472400.c
4379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473c40__FUN_00473c40.c
4380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475040__FUN_00475040.c
4381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004761e0__FUN_004761e0.c
4382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477640__FUN_00477640.c
4383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478200__FUN_00478200.c
4384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479730__FUN_00479730.c
4385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c80__FUN_00479c80.c
4386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a5b0__FUN_0047a5b0.c
4387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bc30__FUN_0047bc30.c
4388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047ca30__FUN_0047ca30.c
4389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f300__FUN_0047f300.c
4390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485870__FUN_00485870.c
4391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004862e0__FUN_004862e0.c
4392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486830__FUN_00486830.c
4393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487260__FUN_00487260.c
4394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487d70__FUN_00487d70.c
4395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488bc0__FUN_00488bc0.c
4396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489970__FUN_00489970.c
4397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048aaa0__sub_48AAA0.c
4398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c0e0__FUN_0048c0e0.c
4399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d380__FUN_0048d380.c
4400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e250__FUN_0048e250.c
4401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f0b0__FUN_0048f0b0.c
4402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe30__FUN_0048fe30.c
4403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004906e0__FUN_004906e0.c
4404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004916e0__FUN_004916e0.c
4405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e60__FUN_00491e60.c
4406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494e60__FUN_00494e60.c
4407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495440__FUN_00495440.c
4408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004962c0__FUN_004962c0.c
4409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004975b0__FUN_004975b0.c
4410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498030__FUN_00498030.c
4411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498950__FUN_00498950.c
4412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004991e0__FUN_004991e0.c
4413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004998e0__FUN_004998e0.c
4414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499da0__FUN_00499da0.c
4415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a190__FUN_0049a190.c
4416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a9c0__FUN_0049a9c0.c
4417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afe0__FUN_0049afe0.c
4418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049bab0__FUN_0049bab0.c
4419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049da60__FUN_0049da60.c
4420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ec40__FUN_0049ec40.c
4421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ffd0__FUN_0049ffd0.c
4422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0da0__FUN_004a0da0.c
4423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1ac0__FUN_004a1ac0.c
4424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2800__FUN_004a2800.c
4425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40c0__FUN_004a40c0.c
4426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5820__FUN_004a5820.c
4427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a7000__sub_4A7000.c
4428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b02b0__FUN_004b02b0.c
4429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1970__FUN_004b1970.c
4430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1fb0__sub_4B1FB0.c
4431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b28f0__FUN_004b28f0.c
4432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c50__FUN_004b2c50.c
4433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3db0__FUN_004b3db0.c
4434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4840__FUN_004b4840.c
4435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5a30__FUN_004b5a30.c
4436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b70b0__FUN_004b70b0.c
4437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b87c0__FUN_004b87c0.c
4438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9ac0__FUN_004b9ac0.c
4439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba180__FUN_004ba180.c
4440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bacf0__FUN_004bacf0.c
4441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb810__FUN_004bb810.c
4442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7a0__FUN_004bd7a0.c
4443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be340__FUN_004be340.c
4444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bffa4__FUN_004bffa4.c
4445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1450__FUN_004c1450.c
4446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c29d0__FUN_004c29d0.c
4447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3050__FUN_004c3050.c
4448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5070__FUN_004c5070.c
4449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6980__FUN_004c6980.c
4450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c30__FUN_004c7c30.c
4451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8580__FUN_004c8580.c
4452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8fc0__FUN_004c8fc0.c
4453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9b80__FUN_004c9b80.c
4454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb5e0__FUN_004cb5e0.c
4455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cdb90__FUN_004cdb90.c
4456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0b00__FUN_004d0b00.c
4457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1c40__FUN_004d1c40.c
4458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4790__FUN_004d4790.c
4459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5be0__FUN_004d5be0.c
4460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7bf0__FUN_004d7bf0.c
4461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d82c4__sub_4D82C4.c
4462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d95d0__FUN_004d95d0.c
4463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db0b0__sub_4DB0B0.c
4464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbe60__FUN_004dbe60.c
4465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcc90__FUN_004dcc90.c
4466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd470__FUN_004dd470.c
4467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfa60__FUN_004dfa60.c
4468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e1970__FUN_004e1970.c
4469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2d00__FUN_004e2d00.c
4470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4e60__FUN_004e4e60.c
4471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e94a3__FUN_004e94a3.c
4472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed0f0__FUN_004ed0f0.c
4473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef680__FUN_004ef680.c
4474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f12e0__FUN_004f12e0.c
4475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f23a0__FUN_004f23a0.c
4476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6b00__FUN_004f6b00.c
4477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f87c0__FUN_004f87c0.c
4478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9140__FUN_004f9140.c
4479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fae70__FUN_004fae70.c
4480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd6d0__FUN_004fd6d0.c
4481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff8f0__FUN_004ff8f0.c
4482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005008e4__FUN_005008e4.c
4483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502bf4__FUN_00502bf4.c
4484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504010__FUN_00504010.c
4485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506559__FUN_00506559.c
4486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508007__FUN_00508007.c
4487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050930b__FUN_0050930b.c
4488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a067__FUN_0050a067.c
4489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab51__FUN_0050ab51.c
4490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b3b5__FUN_0050b3b5.c
4491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b830__FUN_0050b830.c
4492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c48c__FUN_0050c48c.c
4493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cdec__FUN_0050cdec.c
4494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d857__thunk_FUN_0050d84a.c
4495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e04f__FUN_0050e04f.c
4496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e760__FUN_0050e760.c
4497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fab7__FUN_0050fab7.c
4498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511457__FUN_00511457.c
4499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051212e__FUN_0051212e.c
4500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512acc__FUN_00512acc.c
4501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513daf__FUN_00513daf.c
4502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005159a8__FUN_005159a8.c
4503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516531__FUN_00516531.c
4504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517534__sub_517534.c
4505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051923d__FUN_0051923d.c
4506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519f9a__sub_519F9A.c
4507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bd61__FUN_0051bd61.c
4508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cb6d__FUN_0051cb6d.c
4509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dfcb__FUN_0051dfcb.c
4510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051edae__sub_51EDAE.c
4511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051fc80__sub_51FC80.c
4512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521079__sub_521079.c
4513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522ab3__sub_522AB3.c
4514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052692f__FUN_0052692f.c
4515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528bd0__FUN_00528bd0.c
4516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d990__FUN_0052d990.c
4517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e350__FUN_0052e350.c
4518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534aac___AIL_shutdown_0.c
4519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535620__FUN_00535620.c
4520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537d10__FUN_00537d10.c
4521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005397a0__FUN_005397a0.c
4522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b160__FUN_0053b160.c
4523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c190__FUN_0053c190.c
4524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cac0__FUN_0053cac0.c
4525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d450__FUN_0053d450.c
4526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540240__FUN_00540240.c
4527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005414c0__FUN_005414c0.c
4528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005423e0__FUN_005423e0.c
4529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005434a0__FUN_005434a0.c
4530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544e20__FUN_00544e20.c
4531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545820__FUN_00545820.c
4532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546f30__FUN_00546f30.c
4533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547670__FUN_00547670.c
4534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548e00__FUN_00548e00.c
4535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a1b0__FUN_0054a1b0.c
4536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b420__FUN_0054b420.c
4537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c0b0__FUN_0054c0b0.c
4538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d4e0__FUN_0054d4e0.c
4539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054ee90__FUN_0054ee90.c
4540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fca0__FUN_0054fca0.c
4541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550760__FUN_00550760.c
4542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551760__FUN_00551760.c
4543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552910__FUN_00552910.c
4544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553cd0__FUN_00553cd0.c
4545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554be0__FUN_00554be0.c
4546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556650__FUN_00556650.c
4547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556cd0__FUN_00556cd0.c
4548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558b30__FUN_00558b30.c
4549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005597c0__FUN_005597c0.c
4550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bde0__FUN_0055bde0.c
4551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c860__FUN_0055c860.c
4552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d460__FUN_0055d460.c
4553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055fe30__FUN_0055fe30.c
4554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560f40__FUN_00560f40.c
4555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561e30__FUN_00561e30.c
4556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562c90__FUN_00562c90.c
4557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563e80__FUN_00563e80.c
4558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564640__GetTickCount.c
4559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564a20__FUN_00564a20.c
4560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565eb0__FUN_00565eb0.c
4561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566b90__FUN_00566b90.c
4562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005674c0__FUN_005674c0.c
4563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567b10__FUN_00567b10.c
4564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568a60__FUN_00568a60.c
4565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005697a0__FUN_005697a0.c
4566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c020__FUN_0056c020.c
4567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056ead0__FUN_0056ead0.c
4568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579fb0__FUN_00579fb0.c
4569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a420__FUN_0057a420.c
4570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a850__FUN_0057a850.c
4571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057abb0__FUN_0057abb0.c
4572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b530__FUN_0057b530.c
4573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ba10__FUN_0057ba10.c
4574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057de30__FUN_0057de30.c
4575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057f0c8__sub_57F0C8.c
4576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581880__FUN_00581880.c
4577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005823c0__FUN_005823c0.c
4578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005832e0__FUN_005832e0.c
4579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583d40__FUN_00583d40.c
4580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585320__FUN_00585320.c
4581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e10__FUN_00585e10.c
4582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586500__FUN_00586500.c
4583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586ee0__FUN_00586ee0.c
4584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587260__FUN_00587260.c
4585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587710__FUN_00587710.c
4586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587c20__FUN_00587c20.c
4587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588410__FUN_00588410.c
4588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588c7a__FUN_00588c7a.c
4589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005898d3__FUN_005898d3.c
4590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589fcc__FUN_00589fcc.c
4591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a5d8__FUN_0058a5d8.c
4592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ab58__FUN_0058ab58.c
4593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b903__FUN_0058b903.c
4594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c1b1__FUN_0058c1b1.c
4595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d78e__FUN_0058d78e.c
4596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd4b____math_exit.c
4597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ef48__FUN_0058ef48.c
4598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ffec__FUN_0058ffec.c
4599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005910a1__sub_5910A1.c
4600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e89__FUN_00591e89.c
4601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005932ba__FUN_005932ba.c
4602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593e46__FUN_00593e46.c
4603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059525d__FUN_0059525d.c
4604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595ac0__FUN_00595ac0.c
4605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596c20__FUN_00596c20.c
4606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005975c6__FUN_005975c6.c
4607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059863c__bind.c
4608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986cb__sub_5986CB.c
4609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059880b__sub_59880B.c
4610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e2e__FUN_00598e2e.c
4611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599485__FUN_00599485.c
4612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997f5__FUN_005997f5.c
4613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599933__FUN_00599933.c
4614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a103__FUN_0059a103.c
4615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a54d__FUN_0059a54d.c
4616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aaa3__FUN_0059aaa3.c
4617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059afff__FUN_0059afff.c
4618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059baa3__FUN_0059baa3.c
4619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c30e__FUN_0059c30e.c
4620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c50e__Unwind_0059c50e.c
4621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c616__Unwind_0059c616.c
4622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6de__Unwind_0059c6de.c
4623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c830__Unwind_0059c830.c
4624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c93a__Unwind_0059c93a.c
4625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059caa8__sub_59CAA8.c
4626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc13__Unwind_0059cc13.c
4627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd6b__Unwind_0059cd6b.c
4628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ceed__Unwind_0059ceed.c
4629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d004__Unwind_0059d004.c
4630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d110__Unwind_0059d110.c
4631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2bf__Unwind_0059d2bf.c
4632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d45c__Unwind_0059d45c.c
4633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d6a9__FUN_0059d6a9.c
4634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059db5b__FUN_0059db5b.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_N.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
