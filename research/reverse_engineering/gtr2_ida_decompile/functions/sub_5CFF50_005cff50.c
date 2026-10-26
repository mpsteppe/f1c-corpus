char __userpurge sub_5CFF50@<al>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5, int a6, _DWORD *a7)
{
  int v9; // eax
  int v10; // esi
  _DWORD *v11; // eax
  int v12; // esi
  _DWORD *v13; // eax
  _DWORD *v14; // edi
  void (__thiscall ***v15)(_DWORD, int); // ecx
  int i; // ebp
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // edi
  _DWORD *v21; // eax
  int v22; // ecx
  int v23; // [esp+Ch] [ebp-40h]
  _BYTE v24[4]; // [esp+18h] [ebp-34h] BYREF
  int v25; // [esp+1Ch] [ebp-30h]
  int v26; // [esp+20h] [ebp-2Ch]
  int v27; // [esp+24h] [ebp-28h]
  int v28; // [esp+28h] [ebp-24h]
  int v29; // [esp+2Ch] [ebp-20h] BYREF
  unsigned __int16 v30; // [esp+30h] [ebp-1Ch]
  _BYTE v31[4]; // [esp+34h] [ebp-18h] BYREF
  const char *v32; // [esp+38h] [ebp-14h]
  int v33; // [esp+48h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h]

  if ( a6 )
  {
    v23 = a3;
    (*(void (__thiscall **)(int, _BYTE *, int, int))(*(_DWORD *)a4 + 4))(a4, v24, 4, a2);
    sub_5BE610((int)v31, a4);
    retaddr = 0;
    v9 = sub_5C0060();
    v10 = sub_5D1170(v9);
    v11 = operator new(0x24u);
    if ( v11 )
    {
      v11[8] = v10;
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
      *((_BYTE *)v11 + 30) = 0;
      v11[5] = 0;
      v11[4] = 1;
      v11[6] = 1065353216;
      *((_BYTE *)v11 + 29) = 0;
      *((_BYTE *)v11 + 28) = 1;
      v11[3] = 0;
      v12 = (int)v11;
    }
    else
    {
      v12 = 0;
    }
    v13 = operator new(0xCu);
    if ( v13 )
    {
      v13[1] = 0;
      *v13 = &off_72A3FC;
      v13[2] = 0;
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    v15 = *(void (__thiscall ****)(_DWORD, int))(v12 + 12);
    if ( v15 )
      (**v15)(v15, 1);
    *(_DWORD *)(v12 + 12) = v14;
    v14[1] = v12;
    if ( *(_BYTE *)(a1 + 12) )
    {
      sub_643E40("    - Expression Motion Part: %s", v32);
      if ( *(_BYTE *)(a1 + 12) )
      {
        sub_643E40("       + Interpolation Type = Hermite");
        if ( *(_BYTE *)(a1 + 12) )
          sub_643E40("       + NrKeys             = %d", v25);
      }
    }
    for ( i = 0; i < v25; ++i )
    {
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a5 + 4))(a5, &v29, 8);
      v17 = v29;
      v26 = v30;
      *(_BYTE *)(v12 + 30) = 0;
      v28 = v17;
      v18 = *(_DWORD *)(v12 + 4);
      LOBYTE(v27) = (unsigned __int64)((double)v26 * 0.000015259022 * 255.0);
      v19 = *(_DWORD *)v12 + 1;
      *(_DWORD *)v12 = v19;
      if ( v18 < v19 )
      {
        v20 = v19 + 1;
        sub_4F14D0(v23);
        *(_DWORD *)(v12 + 8) = sub_5A8CF0(*(void **)(v12 + 8), 8 * v20, 2, 16, 2);
        *(_DWORD *)(v12 + 4) = v20;
      }
      v21 = (_DWORD *)(*(_DWORD *)(v12 + 8) + 8 * (*(_DWORD *)v12 - 1));
      if ( v21 )
      {
        v22 = v28;
        *v21 = v27;
        v21[1] = v22;
      }
    }
    *(_DWORD *)(v12 + 16) = 0;
    sub_5C6450((int *)v12);
    sub_5C7220(a7, v12);
    sub_5CF6F0(a7);
    v33 = -1;
    sub_5A8840();
    return 1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 12) )
      sub_643E40("Passed motion seems to be not valid!");
    return 0;
  }
}
