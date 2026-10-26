int __thiscall sub_4605E0(_DWORD *this)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int *v10; // edi
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax

  v2 = this + 2052;
  if ( dword_B74854 )
  {
    if ( dword_B74854 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v3 = dword_B74858;
    *v2 = 0;
    byte_B698EC[v2[1]] = 0;
    v2[1] = v3;
    v2[2] = 2;
    byte_B698EC[v3] = 2;
    v2[8] = 0;
    v2[7] = 0;
  }
  if ( dword_B74838 )
  {
    if ( dword_B74838 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v4 = dword_B7483C;
    this[2041] = 0;
    byte_B698EC[this[2042]] = 0;
    this[2042] = v4;
    this[2043] = 2;
    byte_B698EC[v4] = 2;
    this[2049] = 0;
    this[2048] = 0;
  }
  if ( dword_B74800 )
  {
    if ( dword_B74800 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v5 = dword_B74804;
    this[2019] = 0;
    byte_B698EC[this[2020]] = 0;
    this[2020] = v5;
    this[2021] = 2;
    byte_B698EC[v5] = 2;
    this[2027] = 0;
    this[2026] = 0;
  }
  if ( dword_B7481C )
  {
    if ( dword_B7481C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v6 = dword_B74820;
    this[2030] = 0;
    byte_B698EC[this[2031]] = 0;
    this[2031] = v6;
    this[2032] = 2;
    byte_B698EC[v6] = 2;
    this[2038] = 0;
    this[2037] = 0;
  }
  if ( dword_B74870 )
  {
    if ( dword_B74870 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v7 = dword_B74874;
    this[2063] = 0;
    byte_B698EC[this[2064]] = 0;
    this[2064] = v7;
    this[2065] = 2;
    byte_B698EC[v7] = 2;
    this[2071] = 0;
    this[2070] = 0;
  }
  if ( dword_B7488C )
  {
    if ( dword_B7488C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v8 = dword_B74890;
    this[2074] = 0;
    byte_B698EC[this[2075]] = 0;
    this[2075] = v8;
    this[2076] = 2;
    byte_B698EC[v8] = 2;
    this[2082] = 0;
    this[2081] = 0;
  }
  if ( dword_B748A8 )
  {
    if ( dword_B748A8 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v9 = dword_B748AC;
    this[2085] = 0;
    byte_B698EC[this[2086]] = 0;
    this[2086] = v9;
    this[2087] = 2;
    byte_B698EC[v9] = 2;
    this[2093] = 0;
    this[2092] = 0;
  }
  v10 = (int *)&unk_B74BBC;
  v11 = this + 2394;
  do
  {
    v12 = *(v10 - 1);
    if ( byte_B73A08 == 1 )
    {
      if ( v12 )
      {
        if ( v12 == 1 && sub_45F910() )
          goto LABEL_41;
        goto LABEL_49;
      }
      v13 = *v10;
      *(v11 - 1) = 0;
      byte_B698EC[*v11] = 0;
      *v11 = v13;
      v11[1] = 2;
      byte_B698EC[v13] = 2;
LABEL_48:
      v11[7] = 0;
      v11[6] = 0;
      goto LABEL_49;
    }
    if ( !v12 )
    {
      v14 = *v10;
      *(v11 - 1) = 0;
      byte_B698EC[*v11] = 0;
      *v11 = v14;
      v11[1] = 0;
      byte_B698EC[v14] = 0;
      goto LABEL_48;
    }
    if ( v12 == 1 && sub_45F910() )
LABEL_41:
      sub_45F4D0();
LABEL_49:
    v10 += 7;
    v11 += 11;
  }
  while ( (int)v10 <= (int)dword_B74C80 );
  if ( dword_B748C4 )
  {
    if ( dword_B748C4 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v15 = dword_B748C8;
    this[2096] = 0;
    byte_B698EC[this[2097]] = 0;
    this[2097] = v15;
    this[2098] = 2;
    byte_B698EC[v15] = 2;
    this[2104] = 0;
    this[2103] = 0;
  }
  if ( dword_B74A4C )
  {
    if ( dword_B74A4C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v16 = dword_B74A50;
    this[2250] = 0;
    byte_B698EC[this[2251]] = 0;
    this[2251] = v16;
    this[2252] = 0;
    byte_B698EC[v16] = 0;
    this[2258] = 0;
    this[2257] = 0;
  }
  if ( dword_B74B48 )
  {
    if ( dword_B74B48 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v17 = dword_B74B4C;
    this[2349] = 0;
    byte_B698EC[this[2350]] = 0;
    this[2350] = v17;
    this[2351] = 2;
    byte_B698EC[v17] = 2;
    this[2357] = 0;
    this[2356] = 0;
  }
  if ( dword_B74B10 )
  {
    if ( dword_B74B10 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v18 = dword_B74B14;
    this[2327] = 0;
    byte_B698EC[this[2328]] = 0;
    this[2328] = v18;
    this[2329] = 2;
    byte_B698EC[v18] = 2;
    this[2335] = 0;
    this[2334] = 0;
  }
  if ( dword_B74B2C )
  {
    if ( dword_B74B2C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v19 = dword_B74B30;
    this[2338] = 0;
    byte_B698EC[this[2339]] = 0;
    this[2339] = v19;
    this[2340] = 2;
    byte_B698EC[v19] = 2;
    this[2346] = 0;
    this[2345] = 0;
  }
  if ( dword_B74A14 )
  {
    if ( dword_B74A14 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v20 = dword_B74A18;
    this[2228] = 0;
    byte_B698EC[this[2229]] = 0;
    this[2229] = v20;
    this[2230] = 1;
    byte_B698EC[v20] = 1;
    this[2236] = 0;
    this[2235] = 0;
  }
  if ( dword_B74A30 )
  {
    if ( dword_B74A30 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v21 = dword_B74A34;
    this[2239] = 0;
    byte_B698EC[this[2240]] = 0;
    this[2240] = v21;
    this[2241] = 1;
    byte_B698EC[v21] = 1;
    this[2247] = 0;
    this[2246] = 0;
  }
  if ( dword_B748E0 )
  {
    if ( dword_B748E0 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v22 = dword_B748E4;
    this[2107] = 0;
    byte_B698EC[this[2108]] = 0;
    this[2108] = v22;
    this[2109] = 0;
    byte_B698EC[v22] = 0;
    this[2115] = 0;
    this[2114] = 0;
  }
  if ( dword_B74AA0 )
  {
    if ( dword_B74AA0 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v23 = dword_B74AA4;
    this[2283] = 0;
    byte_B698EC[this[2284]] = 0;
    this[2284] = v23;
    this[2285] = 0;
    byte_B698EC[v23] = 0;
    this[2291] = 0;
    this[2290] = 0;
  }
  if ( dword_B748FC )
  {
    if ( dword_B748FC == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v24 = dword_B74900;
    this[2118] = 0;
    byte_B698EC[this[2119]] = 0;
    this[2119] = v24;
    this[2120] = 1;
    byte_B698EC[v24] = 1;
    this[2126] = 0;
    this[2125] = 0;
  }
  if ( dword_B74AF4 )
  {
    if ( dword_B74AF4 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v25 = dword_B74AF8;
    this[2316] = 0;
    byte_B698EC[this[2317]] = 0;
    this[2317] = v25;
    this[2318] = 0;
    byte_B698EC[v25] = 0;
    this[2324] = 0;
    this[2323] = 0;
  }
  if ( dword_B74918 )
  {
    if ( dword_B74918 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v26 = dword_B7491C;
    this[2129] = 0;
    byte_B698EC[this[2130]] = 0;
    this[2130] = v26;
    this[2131] = 0;
    byte_B698EC[v26] = 0;
    this[2137] = 0;
    this[2136] = 0;
  }
  if ( dword_B74934 )
  {
    if ( dword_B74934 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v27 = dword_B74938;
    this[2140] = 0;
    byte_B698EC[this[2141]] = 0;
    this[2141] = v27;
    this[2142] = 0;
    byte_B698EC[v27] = 0;
    this[2148] = 0;
    this[2147] = 0;
  }
  if ( dword_B74950 )
  {
    if ( dword_B74950 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v28 = dword_B74954;
    this[2151] = 0;
    byte_B698EC[this[2152]] = 0;
    this[2152] = v28;
    this[2153] = 0;
    byte_B698EC[v28] = 0;
    this[2159] = 0;
    this[2158] = 0;
  }
  if ( dword_B7496C )
  {
    if ( dword_B7496C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v29 = dword_B74970;
    this[2162] = 0;
    byte_B698EC[this[2163]] = 0;
    this[2163] = v29;
    this[2164] = 0;
    byte_B698EC[v29] = 0;
    this[2170] = 0;
    this[2169] = 0;
  }
  if ( dword_B74988 )
  {
    if ( dword_B74988 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v30 = dword_B7498C;
    this[2173] = 0;
    byte_B698EC[this[2174]] = 0;
    this[2174] = v30;
    this[2175] = 0;
    byte_B698EC[v30] = 0;
    this[2181] = 0;
    this[2180] = 0;
  }
  if ( dword_B749A4 )
  {
    if ( dword_B749A4 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v31 = dword_B749A8;
    this[2184] = 0;
    byte_B698EC[this[2185]] = 0;
    this[2185] = v31;
    this[2186] = 0;
    byte_B698EC[v31] = 0;
    this[2192] = 0;
    this[2191] = 0;
  }
  if ( dword_B749C0 )
  {
    if ( dword_B749C0 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v32 = dword_B749C4;
    this[2195] = 0;
    byte_B698EC[this[2196]] = 0;
    this[2196] = v32;
    this[2197] = 1;
    byte_B698EC[v32] = 1;
    this[2203] = 0;
    this[2202] = 0;
  }
  if ( dword_B749DC )
  {
    if ( dword_B749DC == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v33 = dword_B749E0;
    this[2206] = 0;
    byte_B698EC[this[2207]] = 0;
    this[2207] = v33;
    this[2208] = 1;
    byte_B698EC[v33] = 1;
    this[2214] = 0;
    this[2213] = 0;
  }
  if ( dword_B74B64 )
  {
    if ( dword_B74B64 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v34 = dword_B74B68;
    this[2360] = 0;
    byte_B698EC[this[2361]] = 0;
    this[2361] = v34;
    this[2362] = 0;
    byte_B698EC[v34] = 0;
    this[2368] = 0;
    this[2367] = 0;
  }
  if ( dword_B74B80 )
  {
    if ( dword_B74B80 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v35 = dword_B74B84;
    this[2371] = 0;
    byte_B698EC[this[2372]] = 0;
    this[2372] = v35;
    this[2373] = 2;
    byte_B698EC[v35] = 2;
    this[2379] = 0;
    this[2378] = 0;
  }
  if ( dword_B74B9C )
  {
    if ( dword_B74B9C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v36 = dword_B74BA0;
    this[2382] = 0;
    byte_B698EC[this[2383]] = 0;
    this[2383] = v36;
    this[2384] = 2;
    byte_B698EC[v36] = 2;
    this[2390] = 0;
    this[2389] = 0;
  }
  if ( dword_B74ABC )
  {
    if ( dword_B74ABC == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v37 = dword_B74AC0;
    this[2294] = 0;
    byte_B698EC[this[2295]] = 0;
    this[2295] = v37;
    this[2296] = 0;
    byte_B698EC[v37] = 0;
    this[2302] = 0;
    this[2301] = 0;
  }
  if ( dword_B74A68 )
  {
    if ( dword_B74A68 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v38 = dword_B74A6C;
    this[2261] = 0;
    byte_B698EC[this[2262]] = 0;
    this[2262] = v38;
    this[2263] = 0;
    byte_B698EC[v38] = 0;
    this[2269] = 0;
    this[2268] = 0;
  }
  if ( dword_B74A84 )
  {
    if ( dword_B74A84 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v39 = dword_B74A88;
    this[2272] = 0;
    byte_B698EC[this[2273]] = 0;
    this[2273] = v39;
    this[2274] = 0;
    byte_B698EC[v39] = 0;
    this[2280] = 0;
    this[2279] = 0;
  }
  if ( dword_B74C98 )
  {
    if ( dword_B74C98 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v40 = dword_B74C9C;
    this[2481] = 0;
    byte_B698EC[this[2482]] = 0;
    this[2482] = v40;
    this[2483] = 0;
    byte_B698EC[v40] = 0;
    this[2489] = 0;
    this[2488] = 0;
  }
  if ( dword_B74CB4 )
  {
    if ( dword_B74CB4 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v41 = dword_B74CB8;
    this[2492] = 0;
    byte_B698EC[this[2493]] = 0;
    this[2493] = v41;
    this[2494] = 0;
    byte_B698EC[v41] = 0;
    this[2500] = 0;
    this[2499] = 0;
  }
  if ( dword_B74CD0 )
  {
    if ( dword_B74CD0 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v42 = dword_B74CD4;
    this[2503] = 0;
    byte_B698EC[this[2504]] = 0;
    this[2504] = v42;
    this[2505] = 2;
    byte_B698EC[v42] = 2;
    this[2511] = 0;
    this[2510] = 0;
  }
  if ( dword_B749F8 )
  {
    if ( dword_B749F8 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v43 = dword_B749FC;
    this[2217] = 0;
    byte_B698EC[this[2218]] = 0;
    this[2218] = v43;
    this[2219] = 0;
    byte_B698EC[v43] = 0;
    this[2225] = 0;
    this[2224] = 0;
  }
  if ( dword_B74CEC )
  {
    if ( dword_B74CEC == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v44 = dword_B74CF0;
    this[2514] = 0;
    byte_B698EC[this[2515]] = 0;
    this[2515] = v44;
    this[2516] = 2;
    byte_B698EC[v44] = 2;
    this[2522] = 0;
    this[2521] = 0;
  }
  if ( dword_B74D08 )
  {
    if ( dword_B74D08 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v45 = dword_B74D0C;
    this[2525] = 0;
    byte_B698EC[this[2526]] = 0;
    this[2526] = v45;
    this[2527] = 2;
    byte_B698EC[v45] = 2;
    this[2533] = 0;
    this[2532] = 0;
  }
  if ( dword_B74D24 )
  {
    if ( dword_B74D24 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v46 = dword_B74D28;
    this[2536] = 0;
    byte_B698EC[this[2537]] = 0;
    this[2537] = v46;
    this[2538] = 2;
    byte_B698EC[v46] = 2;
    this[2544] = 0;
    this[2543] = 0;
  }
  if ( dword_B74D40 )
  {
    if ( dword_B74D40 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v47 = dword_B74D44;
    this[2547] = 0;
    byte_B698EC[this[2548]] = 0;
    this[2548] = v47;
    this[2549] = 2;
    byte_B698EC[v47] = 2;
    this[2555] = 0;
    this[2554] = 0;
  }
  if ( dword_B74D5C )
  {
    if ( dword_B74D5C == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v48 = dword_B74D60;
    this[2558] = 0;
    byte_B698EC[this[2559]] = 0;
    this[2559] = v48;
    this[2560] = 2;
    byte_B698EC[v48] = 2;
    this[2566] = 0;
    this[2565] = 0;
  }
  if ( dword_B74D78 )
  {
    if ( dword_B74D78 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v49 = dword_B74D7C;
    this[2569] = 0;
    byte_B698EC[this[2570]] = 0;
    this[2570] = v49;
    this[2571] = 1;
    byte_B698EC[v49] = 1;
    this[2577] = 0;
    this[2576] = 0;
  }
  if ( dword_B74D94 )
  {
    if ( dword_B74D94 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v50 = dword_B74D98;
    this[2580] = 0;
    byte_B698EC[this[2581]] = 0;
    this[2581] = v50;
    this[2582] = 1;
    byte_B698EC[v50] = 1;
    this[2588] = 0;
    this[2587] = 0;
  }
  if ( dword_B74DB0 )
  {
    if ( dword_B74DB0 == 1 && sub_45F910() )
      sub_45F4D0();
  }
  else
  {
    v51 = dword_B74DB4;
    this[2591] = 0;
    byte_B698EC[this[2592]] = 0;
    this[2592] = v51;
    this[2593] = 1;
    byte_B698EC[v51] = 1;
    this[2599] = 0;
    this[2598] = 0;
  }
  sub_4602E0(this + 2602, dword_B74DCC, 1);
  sub_4602E0(this + 2613, dword_B74DE8, 0);
  sub_4602E0(this + 2624, dword_B74E04, 0);
  sub_4602E0(this + 2635, dword_B74E20, 0);
  sub_4602E0(this + 2646, dword_B74E3C, 0);
  sub_4602E0(this + 2657, dword_B74E58, 0);
  sub_4602E0(this + 2668, dword_B74E74, 0);
  sub_4602E0(this + 2679, dword_B74E90, 0);
  sub_4602E0(this + 2690, dword_B74EAC, 0);
  sub_4602E0(this + 2701, dword_B74EC8, 0);
  sub_4602E0(this + 2712, dword_B74EE4, 0);
  sub_4602E0(this + 2723, dword_B74F00, 0);
  sub_4602E0(this + 2734, dword_B74F1C, 0);
  sub_4602E0(this + 2745, dword_B74F38, 0);
  sub_4602E0(this + 2756, dword_B74F54, 0);
  return sub_4602E0(this + 2305, dword_B74AD8, 0);
}
