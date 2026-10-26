# WORKER T — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker T of 20, items 6287–6616.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_T.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (330)

6287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403f70__FUN_00403f70.c
6288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d20__FUN_00404d20.c
6289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004054e0__FUN_004054e0.c
6290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004060c0__FUN_004060c0.c
6291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406cc0__FUN_00406cc0.c
6292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407f10__FUN_00407f10.c
6293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408500__FUN_00408500.c
6294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ac60__sub_40AC60.c
6295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040be20__FUN_0040be20.c
6296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040cde0__FUN_0040cde0.c
6297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dbc0__FUN_0040dbc0.c
6298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e8b0__FUN_0040e8b0.c
6299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040fb30__FUN_0040fb30.c
6300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411680__FUN_00411680.c
6301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00413600__FUN_00413600.c
6302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004145c0__FUN_004145c0.c
6303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004159b0__FUN_004159b0.c
6304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418d60__FUN_00418d60.c
6305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a500__FUN_0041a500.c
6306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041e320__FUN_0041e320.c
6307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041fc60__FUN_0041fc60.c
6308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421970__FUN_00421970.c
6309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004234c0__FUN_004234c0.c
6310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00425660__FUN_00425660.c
6311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a740__FUN_0042a740.c
6312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042b0e0__FUN_0042b0e0.c
6313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dbf0__FUN_0042dbf0.c
6314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ec00__FUN_0042ec00.c
6315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431a70__FUN_00431a70.c
6316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432980__FUN_00432980.c
6317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433ed0__FUN_00433ed0.c
6318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004352c0__FUN_004352c0.c
6319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438690__FUN_00438690.c
6320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e360__FUN_0043e360.c
6321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004414d0__FUN_004414d0.c
6322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447160__FUN_00447160.c
6323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004484f0__FUN_004484f0.c
6324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004492d0__FUN_004492d0.c
6325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044aa30__FUN_0044aa30.c
6326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c620__FUN_0044c620.c
6327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c9e0__FUN_0044c9e0.c
6328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc80__FUN_0044cc80.c
6329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cef0__FUN_0044cef0.c
6330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d1f0__FUN_0044d1f0.c
6331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d580__FUN_0044d580.c
6332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d940__FUN_0044d940.c
6333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd00__FUN_0044dd00.c
6334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0c0__FUN_0044e0c0.c
6335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e480__FUN_0044e480.c
6336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e840__FUN_0044e840.c
6337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec00__FUN_0044ec00.c
6338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f5e2__sub_44F5E2.c
6339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452740__FUN_00452740.c
6340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455560__FUN_00455560.c
6341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004562c0__FUN_004562c0.c
6342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004584a0__FUN_004584a0.c
6343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b3e0__FUN_0045b3e0.c
6344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bc50__FUN_0045bc50.c
6345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c400__FUN_0045c400.c
6346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d260__FUN_0045d260.c
6347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045f4a0__FUN_0045f4a0.c
6348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004618d0__FUN_004618d0.c
6349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462410__FUN_00462410.c
6350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004636a0__FUN_004636a0.c
6351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464670__FUN_00464670.c
6352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464d30__FUN_00464d30.c
6353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466050__FUN_00466050.c
6354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466c40__FUN_00466c40.c
6355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004694b0__FUN_004694b0.c
6356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046af00__FUN_0046af00.c
6357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d270__FUN_0046d270.c
6358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e7d0__FUN_0046e7d0.c
6359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470040__FUN_00470040.c
6360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471540__FUN_00471540.c
6361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472a80__FUN_00472a80.c
6362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473fd0__FUN_00473fd0.c
6363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475920__FUN_00475920.c
6364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004766f0__FUN_004766f0.c
6365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477ba0__FUN_00477ba0.c
6366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478350__FUN_00478350.c
6367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479850__FUN_00479850.c
6368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479e50__FUN_00479e50.c
6369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a9e0__FUN_0047a9e0.c
6370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be90__FUN_0047be90.c
6371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047e680__FUN_0047e680.c
6372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047fbd0__FUN_0047fbd0.c
6373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485a90__FUN_00485a90.c
6374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486400__FUN_00486400.c
6375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486ec8__sub_486EC8.c
6376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487530__FUN_00487530.c
6377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f70__FUN_00487f70.c
6378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004893c0__FUN_004893c0.c
6379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489c60__FUN_00489c60.c
6380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b4f0__FUN_0048b4f0.c
6381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c9e0__FUN_0048c9e0.c
6382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d660__FUN_0048d660.c
6383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e600__FUN_0048e600.c
6384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f640__FUN_0048f640.c
6385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004900a0__FUN_004900a0.c
6386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490b00__FUN_00490b00.c
6387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004918d0__FUN_004918d0.c
6388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00493e20__FUN_00493e20.c
6389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494fe0__FUN_00494fe0.c
6390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004958d0__FUN_004958d0.c
6391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496840__FUN_00496840.c
6392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497890__FUN_00497890.c
6393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498550__FUN_00498550.c
6394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498e30__FUN_00498e30.c
6395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499520__FUN_00499520.c
6396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a50__FUN_00499a50.c
6397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e40__FUN_00499e40.c
6398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2c0__thunk_FUN_00566650.c
6399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aad0__sub_49AAD0.c
6400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b200__FUN_0049b200.c
6401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049c898__sub_49C898.c
6402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e4e0__FUN_0049e4e0.c
6403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ed20__FUN_0049ed20.c
6404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0630__FUN_004a0630.c
6405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0e68__sub_4A0E68.c
6406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1da0__FUN_004a1da0.c
6407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3390__FUN_004a3390.c
6408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a46f0__FUN_004a46f0.c
6409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5e10__FUN_004a5e10.c
6410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8b30__FUN_004a8b30.c
6411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b09a0__FUN_004b09a0.c
6412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a30__FUN_004b1a30.c
6413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b21a0__sub_4B21A0.c
6414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a30__FUN_004b2a30.c
6415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3400__FUN_004b3400.c
6416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b42e0__FUN_004b42e0.c
6417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4f70__FUN_004b4f70.c
6418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5f60__FUN_004b5f60.c
6419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b7a90__FUN_004b7a90.c
6420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9000__FUN_004b9000.c
6421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9ce0__FUN_004b9ce0.c
6422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba790__FUN_004ba790.c
6423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb0c0__FUN_004bb0c0.c
6424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bbf70__FUN_004bbf70.c
6425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd8c0__FUN_004bd8c0.c
6426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004beb10__FUN_004beb10.c
6427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c07f0__FUN_004c07f0.c
6428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1820__FUN_004c1820.c
6429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2c20__FUN_004c2c20.c
6430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4080__FUN_004c4080.c
6431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5830__FUN_004c5830.c
6432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6f10__FUN_004c6f10.c
6433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7dd0__FUN_004c7dd0.c
6434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8830__FUN_004c8830.c
6435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c92b0__FUN_004c92b0.c
6436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9d30__FUN_004c9d30.c
6437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc1d0__sub_4CC1D0.c
6438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ce860__FUN_004ce860.c
6439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0f10__FUN_004d0f10.c
6440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d21d0__FUN_004d21d0.c
6441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4860__FUN_004d4860.c
6442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6800__FUN_004d6800.c
6443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7da0__FUN_004d7da0.c
6444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8880__FUN_004d8880.c
6445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004da080__FUN_004da080.c
6446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db170__FUN_004db170.c
6447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc290__FUN_004dc290.c
6448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcdd0__FUN_004dcdd0.c
6449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd7c0__FUN_004dd7c0.c
6450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0800__FUN_004e0800.c
6451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e21d0__FUN_004e21d0.c
6452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e39d0__FUN_004e39d0.c
6453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e5470__FUN_004e5470.c
6454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9a40__FUN_004e9a40.c
6455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed420__FUN_004ed420.c
6456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efae0__FUN_004efae0.c
6457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f17d0__FUN_004f17d0.c
6458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f3190__FUN_004f3190.c
6459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6d90__FUN_004f6d90.c
6460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8ae0__FUN_004f8ae0.c
6461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9230__FUN_004f9230.c
6462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb6d0__FUN_004fb6d0.c
6463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fdeb0__FUN_004fdeb0.c
6464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500161__FUN_00500161.c
6465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500fae__FUN_00500fae.c
6466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005033a5__FUN_005033a5.c
6467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504731__FUN_00504731.c
6468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507079__FUN_00507079.c
6469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005085c5__FUN_005085c5.c
6470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509812__FUN_00509812.c
6471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a3ce__FUN_0050a3ce.c
6472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050aeae__FUN_0050aeae.c
6473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b446__FUN_0050b446.c
6474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c042__FUN_0050c042.c
6475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c636__FUN_0050c636.c
6476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0c2__FUN_0050d0c2.c
6477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dab2__sub_50DAB2.c
6478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e19e__FUN_0050e19e.c
6479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050eb73__FUN_0050eb73.c
6480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fdf3__FUN_0050fdf3.c
6481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005116a3__sub_5116A3.c
6482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512319__FUN_00512319.c
6483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513a56__FUN_00513a56.c
6484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005147ea__FUN_005147ea.c
6485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515df2__sub_515DF2.c
6486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516959__FUN_00516959.c
6487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005179a2__FUN_005179a2.c
6488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051941d__FUN_0051941d.c
6489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a968__FUN_0051a968.c
6490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c086__sub_51C086.c
6491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cf80__FUN_0051cf80.c
6492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e512__FUN_0051e512.c
6493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f2c0__sub_51F2C0.c
6494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052014e__sub_52014E.c
6495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052179f__FUN_0052179f.c
6496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052401f__sub_52401F.c
6497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527578__FUN_00527578.c
6498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529700__FUN_00529700.c
6499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052dd50__sub_52DD50.c
6500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e5a0__FUN_0052e5a0.c
6501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534d50__FUN_00534d50.c
6502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005361d0__FUN_005361d0.c
6503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005381f0__sub_5381F0.c
6504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ab20__FUN_0053ab20.c
6505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b350__FUN_0053b350.c
6506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c360__FUN_0053c360.c
6507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ced0__FUN_0053ced0.c
6508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d890__FUN_0053d890.c
6509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540cb0__FUN_00540cb0.c
6510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541810__FUN_00541810.c
6511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005424e0__FUN_005424e0.c
6512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543870__FUN_00543870.c
6513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005450e0__FUN_005450e0.c
6514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545a40__FUN_00545a40.c
6515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547140__FUN_00547140.c
6516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547b40__FUN_00547b40.c
6517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549110__FUN_00549110.c
6518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a340__FUN_0054a340.c
6519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b770__FUN_0054b770.c
6520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c1b0__FUN_0054c1b0.c
6521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e0e0__FUN_0054e0e0.c
6522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f7a0__FUN_0054f7a0.c
6523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fda0__FUN_0054fda0.c
6524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550820__FUN_00550820.c
6525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005519e0__FUN_005519e0.c
6526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552ff0__FUN_00552ff0.c
6527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553fa0__FUN_00553fa0.c
6528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554e90__FUN_00554e90.c
6529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567a9__FUN_005567a9.c
6530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557280__FUN_00557280.c
6531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558dc0__FUN_00558dc0.c
6532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559d80__FUN_00559d80.c
6533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bfd0__FUN_0055bfd0.c
6534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055cc20__FUN_0055cc20.c
6535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d720__FUN_0055d720.c
6536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056068e__FUN_0056068e.c
6537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561660__FUN_00561660.c
6538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562090__FUN_00562090.c
6539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563160__FUN_00563160.c
6540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564270__FUN_00564270.c
6541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564740__FUN_00564740.c
6542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564dd0__FUN_00564dd0.c
6543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005662d0__FUN_005662d0.c
6544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566d30__FUN_00566d30.c
6545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005677b0__FUN_005677b0.c
6546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567e10__FUN_00567e10.c
6547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568cf0__FUN_00568cf0.c
6548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569ad0__FUN_00569ad0.c
6549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056c740__FUN_0056c740.c
6550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056ee40__FUN_0056ee40.c
6551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a070__FUN_0057a070.c
6552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a590__FUN_0057a590.c
6553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a908__sub_57A908.c
6554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae30__FUN_0057ae30.c
6555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b6b0__FUN_0057b6b0.c
6556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057bce0__FUN_0057bce0.c
6557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e6e0__FUN_0057e6e0.c
6558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00580190__FUN_00580190.c
6559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581ad0__FUN_00581ad0.c
6560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582a10__FUN_00582a10.c
6561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583570__FUN_00583570.c
6562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584130__FUN_00584130.c
6563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585550__FUN_00585550.c
6564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585f30__FUN_00585f30.c
6565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005867b0__FUN_005867b0.c
6566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587030__FUN_00587030.c
6567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587440__FUN_00587440.c
6568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587930__FUN_00587930.c
6569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587dd0___strncpy.c
6570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588640___strncmp.c
6571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005891fe__FUN_005891fe.c
6572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589bc6__FUN_00589bc6.c
6573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a163__FUN_0058a163.c
6574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a755__FUN_0058a755.c
6575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ae69__FUN_0058ae69.c
6576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bb10___memset.c
6577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c38e__FUN_0058c38e.c
6578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058d9be__sub_58D9BE.c
6579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dfea__FUN_0058dfea.c
6580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058f6c7__FUN_0058f6c7.c
6581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005903da__FUN_005903da.c
6582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059168f__FUN_0059168f.c
6583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059249b__FUN_0059249b.c
6584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593839__FUN_00593839.c
6585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594a5e__FUN_00594a5e.c
6586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595524__FUN_00595524.c
6587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596007__FUN_00596007.c
6588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596fed__FUN_00596fed.c
6589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597d3c__FUN_00597d3c.c
6590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598660__gethostbyname.c
6591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598727__sub_598727.c
6592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598aea__FUN_00598aea.c
6593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005991c3__FUN_005991c3.c
6594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599615__FUN_00599615.c
6595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059984f__FUN_0059984f.c
6596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599b86__FUN_00599b86.c
6597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a352__sub_59A352.c
6598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a765__FUN_0059a765.c
6599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac46__sub_59AC46.c
6600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b208__FUN_0059b208.c
6601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bcd2__FUN_0059bcd2.c
6602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c446__Unwind_0059c446.c
6603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c56e__Unwind_0059c56e.c
6604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c652__Unwind_0059c652.c
6605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c730__Unwind_0059c730.c
6606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c878__Unwind_0059c878.c
6607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c988__Unwind_0059c988.c
6608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb33__sub_59CB33.c
6609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc88__Unwind_0059cc88.c
6610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce00__Unwind_0059ce00.c
6611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf2f__Unwind_0059cf2f.c
6612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d050__Unwind_0059d050.c
6613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d17b__Unwind_0059d17b.c
6614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d328__Unwind_0059d328.c
6615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4d8__Unwind_0059d4d8.c
6616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d806__FUN_0059d806.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_T.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
