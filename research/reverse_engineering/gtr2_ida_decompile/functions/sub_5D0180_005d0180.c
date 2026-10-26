char __userpurge sub_5D0180@<al>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5, int a6, _DWORD *a7)
{
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // eax
  int v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // edi
  void (__thiscall ***v14)(_DWORD, int); // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  int v18; // edi
  _DWORD *v19; // eax
  int v20; // [esp+10h] [ebp-64h]
  int v21; // [esp+20h] [ebp-54h]
  int v22; // [esp+20h] [ebp-54h]
  int v23; // [esp+24h] [ebp-50h]
  int v24; // [esp+28h] [ebp-4Ch]
  int v25; // [esp+34h] [ebp-40h] BYREF
  unsigned __int16 v26; // [esp+38h] [ebp-3Ch] BYREF
  char v27[40]; // [esp+3Ch] [ebp-38h] BYREF
  int v28; // [esp+64h] [ebp-10h]
  int retaddr; // [esp+74h] [ebp+0h]
  int i; // [esp+7Ch] [ebp+8h]

  v28 = dword_912B08;
  if ( a6 )
  {
    v20 = a3;
    (*(void (__thiscall **)(int, unsigned __int16 *, int, int))(*(_DWORD *)a4 + 4))(a4, &v26, 44, a2);
    sub_4050C0((int)v27);
    v8 = sub_5C0060();
    v9 = sub_5D1170(v8);
    retaddr = -1;
    sub_5A8840();
    v10 = operator new(0x24u);
    if ( v10 )
    {
      v10[8] = v9;
      *v10 = 0;
      v10[1] = 0;
      v10[2] = 0;
      *((_BYTE *)v10 + 30) = 0;
      v10[5] = 0;
      v10[4] = 1;
      v10[6] = 1065353216;
      *((_BYTE *)v10 + 29) = 0;
      *((_BYTE *)v10 + 28) = 1;
      v10[3] = 0;
      v11 = (int)v10;
    }
    else
    {
      v11 = 0;
    }
    v12 = operator new(0xCu);
    if ( v12 )
    {
      v12[1] = 0;
      *v12 = &off_72A3FC;
      v12[2] = 0;
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    v14 = *(void (__thiscall ****)(_DWORD, int))(v11 + 12);
    if ( v14 )
      (**v14)(v14, 1);
    *(_DWORD *)(v11 + 12) = v13;
    v13[1] = v11;
    if ( *(_BYTE *)(v21 + 12) )
    {
      sub_643E40("    - Expression Motion Part: %s", v27);
      if ( *(_BYTE *)(v21 + 12) )
      {
        sub_643E40("       + Interpolation Type = Hermite");
        if ( *(_BYTE *)(v21 + 12) )
          sub_643E40("       + NrKeys             = %d", v28);
      }
    }
    for ( i = 0; i < v28; ++i )
    {
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a4 + 4))(a4, &v25, 8);
      v15 = v25;
      v22 = v26;
      *(_BYTE *)(v11 + 30) = 0;
      v24 = v15;
      v16 = *(_DWORD *)(v11 + 4);
      v17 = *(_DWORD *)v11 + 1;
      *(_DWORD *)v11 = v17;
      if ( v16 < v17 )
      {
        v18 = v17 + 1;
        sub_4F14D0(v20);
        *(_DWORD *)(v11 + 8) = sub_5A8CF0(*(void **)(v11 + 8), 8 * v18, 2, 16, 2);
        *(_DWORD *)(v11 + 4) = v18;
      }
      v19 = (_DWORD *)(*(_DWORD *)(v11 + 8) + 8 * *(_DWORD *)v11 - 8);
      if ( *(_DWORD *)(v11 + 8) + 8 * *(_DWORD *)v11 != 8 )
      {
        LOBYTE(v23) = (unsigned __int64)((double)v22 * 0.000015259022 * 255.0);
        *v19 = v23;
        v19[1] = v24;
      }
    }
    *(_DWORD *)(v11 + 16) = 0;
    sub_5C6450((int *)v11);
    sub_5C7220(a7, v11);
    sub_5CF6F0(a7);
    return 1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 12) )
      sub_643E40("Passed motion seems to be not valid!");
    return 0;
  }
}
