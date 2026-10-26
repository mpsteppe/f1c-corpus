int __usercall sub_4A5180@<eax>(int *a1@<ecx>, int a2@<ebx>)
{
  int v3; // edx
  int v4; // eax
  int *v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  int v19; // edx
  int v20; // edi
  int v21; // ecx
  int result; // eax
  int v23; // ebp
  int v24; // eax
  int v25; // ecx
  _DWORD *v26; // edi
  int v27; // eax
  int v28; // edx
  int v29; // ebx
  int v30; // ecx
  int v31; // eax
  int v32; // ebx
  int v34; // [esp+0h] [ebp-18h]
  int v35; // [esp+8h] [ebp-10h]
  int v36; // [esp+Ch] [ebp-Ch] BYREF
  int v37; // [esp+10h] [ebp-8h] BYREF
  int v38; // [esp+14h] [ebp-4h]

  v3 = a1[92];
  v36 = a1[85] - a1[84];
  v4 = a1[93] - v3;
  a1[100] = 0;
  a1[101] = 0;
  a1[98] = 0;
  a1[99] = 0;
  a1[103] = 0;
  v37 = v4;
  v5 = (int *)a1[71];
  a1[73] = (int)v5;
  if ( v5 )
    v6 = *v5;
  else
    v6 = 0;
  v7 = a1[74];
  if ( v6 )
  {
    do
    {
      if ( a1[100] < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6) )
        a1[100] = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6);
      if ( a1[101] < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6) )
        a1[101] = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6);
      v8 = a1[73];
      if ( !v8 )
        break;
      v9 = *(int **)(v8 + 4);
      a1[73] = (int)v9;
      if ( !v9 )
        break;
      v6 = *v9;
    }
    while ( *v9 );
  }
  v10 = a1[75];
  if ( v10 )
  {
    if ( v10 == 1 )
    {
      v11 = a1[100];
      if ( v11 )
        a1[99] = v36 / (v11 + a1[96]);
      if ( !a1[99] && v7 > 0 )
        a1[99] = 1;
      v12 = a1[99];
      if ( v12 )
      {
        a1[98] = v7 / v12;
        if ( v7 % v12 > 0 )
          ++a1[98];
        a1[103] = v7 / v12;
        if ( v7 % v12 > 0 )
          a1[103] = v7 / v12 + 1;
      }
      else
      {
        a1[103] = v7;
      }
      v38 = a1[97] + a1[101];
      v13 = v38;
      if ( v38 )
        a1[103] -= (__int64)((double)v37 / (double)v38 + 0.5);
      if ( a1[103] < 0 )
        a1[103] = 0;
      a1[103] *= v13;
    }
  }
  else
  {
    v14 = a1[101];
    if ( v14 )
      a1[98] = v37 / (v14 + a1[97]);
    if ( !a1[98] && v7 > 0 )
      a1[98] = 1;
    v15 = a1[99];
    if ( v15 )
      a1[99] = v7 / v15;
    v16 = a1[98];
    if ( v16 && v7 % v16 > 0 )
      ++a1[99];
    v17 = a1[100];
    if ( v17 )
      a1[103] = a1[99] - v36 / v17;
    if ( a1[103] < 0 )
      a1[103] = 0;
  }
  v18 = a2;
  if ( a1[99] * (a1[100] + a1[96]) > v36 || a1[98] * (a1[101] + a1[97]) > v37 )
  {
    v19 = *a1;
    a1[77] = 0;
    (*(void (__thiscall **)(int *, _DWORD))(v19 + 44))(a1, 0);
  }
  v34 = v18;
  v37 = 0;
  v36 = 0;
  v20 = 0;
  sub_4AE870(&v37, &v36);
  v21 = a1[100] + a1[96];
  if ( v21 )
    v20 = (a1[85] - a1[84]) / v21;
  if ( v20 >= a1[74] )
    v20 = a1[74];
  result = a1[85] - v20 * v21 - a1[84];
  v35 = result;
  if ( a1[98] > 0 )
  {
    while ( 1 )
    {
      v23 = 0;
      if ( a1[99] > 0 )
        break;
LABEL_74:
      result = ++v34;
      if ( v34 >= a1[98] )
        return result;
    }
    while ( 1 )
    {
      v24 = v23;
      if ( v23 >= 0 && v23 < a1[74] )
      {
        v25 = a1[71];
        if ( v23 > 0 )
        {
          while ( v25 )
          {
            v25 = *(_DWORD *)(v25 + 4);
            if ( --v24 <= 0 )
              goto LABEL_58;
          }
          goto LABEL_73;
        }
LABEL_58:
        if ( v25 )
        {
          v26 = *(_DWORD **)v25;
          if ( *(_DWORD *)v25 )
            break;
        }
      }
LABEL_73:
      if ( ++v23 >= a1[99] )
        goto LABEL_74;
    }
    v27 = a1[75];
    v28 = 0;
    v29 = 0;
    if ( v27 )
    {
      if ( v27 == 1 )
        v29 = a1[102];
    }
    else
    {
      v28 = a1[102];
    }
    v30 = a1[84] + v23 * (a1[96] + a1[100]) - v28;
    if ( a1[67] == 1 )
    {
      v31 = v35 / 2;
    }
    else
    {
      if ( a1[67] != 2 )
      {
LABEL_69:
        sub_4A4640(v26, v30, a1[92] - v29);
        v32 = v26[4];
        if ( v32 < a1[92] || v32 + (*(int (**)(void))(*v26 + 8))() > a1[93] )
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*v26 + 24))(v26, 0);
        else
          (*(void (__thiscall **)(_DWORD *, int))(*v26 + 24))(v26, 1);
        goto LABEL_73;
      }
      v31 = v35;
    }
    v30 += v31;
    goto LABEL_69;
  }
  return result;
}
