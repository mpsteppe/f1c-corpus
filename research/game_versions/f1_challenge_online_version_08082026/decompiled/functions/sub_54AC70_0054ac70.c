int __thiscall sub_54AC70(void *this, int a2, int a3, void **a4, int a5)
{
  int v5; // edx
  int v6; // eax
  char v7; // cl
  int v8; // eax
  int v9; // esi
  int v11; // ebx
  int v12; // ecx
  int v13; // ebp
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  int v16; // eax
  int v17; // edi
  unsigned int v18; // ebp
  int v19; // ebx
  unsigned int v20; // ebp
  _DWORD *v21; // edi
  int v22; // eax
  int v23; // esi
  _DWORD *v24; // eax
  unsigned int v25; // esi
  void *v26; // ebx
  _DWORD *i; // esi
  char v29[16]; // [esp+14h] [ebp-10h] BYREF
  _DWORD *v30; // [esp+28h] [ebp+4h]
  int v31; // [esp+34h] [ebp+10h]

  if ( a5 )
  {
    v5 = *(_DWORD *)(a5 + 296);
    v6 = *(_DWORD *)(a5 + 292) << 8;
    v7 = *(_BYTE *)(v6 + v5);
    v8 = v5 + v6;
    if ( (v7 & 0x10) != 0 )
    {
      v9 = *(_DWORD *)(v8 + 12);
      dword_8B8F30 = sub_587C03(*(_DWORD *)(v8 + 8));
      dword_8B8F34 = sub_587C03(v9);
      if ( sub_58803F(dword_8B8F34, 1, v9, a2) != v9 )
      {
        sub_587BCF((LPVOID)dword_8B8F30);
        dword_8B8F30 = 0;
        sub_587BCF((LPVOID)dword_8B8F34);
        dword_8B8F34 = 0;
        return -1;
      }
      sub_59B260(dword_8B8F34, v9);
      goto LABEL_6;
    }
    v31 = *(_DWORD *)(v8 + 8);
    dword_8B8F30 = sub_587C03(v31);
    v16 = sub_58803F(dword_8B8F30, 1, v31, a2);
  }
  else
  {
    v17 = sub_58ACE6(a2);
    sub_587F64(a2, 0, 2);
    v31 = sub_58ACE6(a2) - v17;
    sub_587F64(a2, v17, 0);
    dword_8B8F34 = 0;
    dword_8B8F30 = sub_587C03(v31);
    v16 = sub_58803F(dword_8B8F30, 1, v31, a2);
  }
  if ( v16 != v31 )
  {
    sub_587BCF((LPVOID)dword_8B8F30);
    dword_8B8F30 = 0;
    return -1;
  }
LABEL_6:
  dword_8B8F3C = 0;
  v11 = sub_54A5B0();
  sub_54A5C0(v29, v12, 0x10u);
  v13 = dword_8B8F30;
  sub_54A580(dword_8B8F30, v11, 0);
  if ( !strcmp(v29, aCubeMts410) )
  {
    sub_54A5C0(v29, v13, 0x10u);
    v23 = sub_54A5B0();
    v24 = (_DWORD *)sub_587C03(48);
    if ( v24 )
      v21 = sub_5473D0(v24);
    else
      v21 = 0;
    if ( sub_548190(v21, (int)this) )
    {
      if ( v21 )
      {
        j_nullsub_3(v21);
        sub_587BCF(v21);
      }
      goto LABEL_17;
    }
    sub_54A580(dword_8B8F30, v23, 0);
    if ( sub_548190(*(_DWORD **)(dword_8B8F28 + 272), (int)this) )
      goto LABEL_19;
    v25 = a3 - sub_54A5B0();
    *a4 = (void *)sub_587C03(v25);
    sub_54C320(0);
    if ( sub_54A5C0(*a4, dword_8B8F30, v25) != v25 )
    {
      v26 = *a4;
      if ( *a4 )
      {
        j_nullsub_3(v26);
        sub_587BCF(v26);
      }
LABEL_21:
      sub_53C590(-1, aErrorReadingMe);
      return -1;
    }
    v22 = 0;
  }
  else
  {
    v14 = (_DWORD *)sub_587C03(48);
    if ( v14 )
    {
      v15 = sub_5473D0(v14);
      v30 = v15;
    }
    else
    {
      v30 = 0;
      v15 = 0;
    }
    if ( sub_547B40(v15, (int)this) )
    {
      if ( v15 )
      {
        j_nullsub_3(v15);
        sub_587BCF(v15);
      }
LABEL_17:
      sub_53C590(-1, aErrorAllocatin);
      return -1;
    }
    sub_54A580(dword_8B8F30, v11, 0);
    if ( sub_547B40(*(_DWORD **)(dword_8B8F28 + 272), (int)this) )
    {
LABEL_19:
      sub_53C590(-1, aErrorReadingSc);
      return -1;
    }
    v18 = v11 - sub_54A5B0() + a3;
    v19 = sub_587C03(v18);
    sub_54E9B0(0);
    if ( sub_54A5C0((void *)v19, dword_8B8F30, v18) != v18 )
      goto LABEL_21;
    if ( strcmp((const char *)v19, aCubeMts401) )
    {
      if ( v19 )
      {
        j_nullsub_3(v19);
        sub_587BCF((LPVOID)v19);
      }
      sub_53C590(-1, aWrongMtsVersio);
      return -1;
    }
    v20 = v18 + 96;
    *a4 = (void *)sub_587C03(v20);
    sub_54C320(0);
    qmemcpy((char *)*a4 + 328, (const void *)(v19 + 232), v20 - 328);
    sub_54B190(v19, *a4);
    sub_587BCF((LPVOID)v19);
    v21 = v30;
    v22 = 96;
  }
  if ( sub_54C510(v21, v22) )
    return -1;
  sub_54B330(64, 32, 0);
  for ( i = (_DWORD *)v21[9]; i; i = (_DWORD *)i[48] )
    sub_547710(v21, i);
  sub_547420(v21);
  j_nullsub_3(v21);
  sub_587BCF(v21);
  if ( dword_8B8F30 )
    sub_587BCF((LPVOID)dword_8B8F30);
  if ( dword_8B8F34 )
    sub_587BCF((LPVOID)dword_8B8F34);
  dword_8B8F30 = 0;
  dword_8B8F34 = 0;
  return 0;
}
