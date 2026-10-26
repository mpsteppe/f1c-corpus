char __userpurge sub_59E8A0@<al>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5, int a6, int a7)
{
  void *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // esi
  DWORD v11; // eax
  _DWORD *v12; // eax
  bool v13; // zf
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  _DWORD *v24; // [esp+8h] [ebp-4Ch] BYREF
  int v25; // [esp+Ch] [ebp-48h]
  int v26; // [esp+10h] [ebp-44h]
  int v27; // [esp+14h] [ebp-40h]
  _BYTE v28[4]; // [esp+1Ch] [ebp-38h] BYREF
  _BYTE v29[4]; // [esp+20h] [ebp-34h] BYREF
  _DWORD v30[2]; // [esp+2Ch] [ebp-28h] BYREF
  int v31; // [esp+34h] [ebp-20h]
  int v32; // [esp+3Ch] [ebp-18h]
  char v33; // [esp+40h] [ebp-14h]
  int v34; // [esp+44h] [ebp-10h]
  _DWORD *v35; // [esp+48h] [ebp-Ch]
  int v36; // [esp+4Ch] [ebp-8h]

  v27 = a2;
  v26 = a4;
  v25 = a3;
  sub_5A6CF0(v30, -1, 255, 0);
  v34 = 0;
  sub_5A6FB0(v29, v36);
  v8 = (void *)a1[701];
  v9 = a1 + 697;
  v10 = 0;
  v35 = a1 + 697;
  if ( !v8 || (v11 = WaitForSingleObject(v8, a1[702])) != 0 && v11 != 128 )
    v9 = 0;
  v12 = (_DWORD *)*v9;
  v13 = *v9 == 0;
  v9[2] = *v9;
  if ( v13 )
    goto LABEL_14;
  v14 = (_DWORD *)*v12;
  if ( !v14 )
    goto LABEL_14;
  v15 = v30[1];
  do
  {
    if ( v14[5] == v15 )
      v10 = v14;
    v16 = v9[2];
    if ( !v16 )
      break;
    v17 = *(_DWORD **)(v16 + 4);
    v9[2] = v17;
    if ( !v17 )
      break;
    v14 = (_DWORD *)*v17;
  }
  while ( v14 );
  if ( v10 )
  {
    sub_5A7010(v10, v28);
  }
  else
  {
LABEL_14:
    v18 = operator new(0x20u);
    v10 = v18;
    v24 = v18;
    v33 = 1;
    if ( v18 )
    {
      sub_5A6D30(v18, v28);
      *v10 = &off_725FFC;
      v10[7] = 0;
    }
    else
    {
      v10 = 0;
    }
    LOBYTE(v32) = 0;
    sub_5FDFB0(v10, 1);
    if ( sub_6442E0(v10) == 2 && (_BYTE)v36 )
    {
      htonl(0);
      htons(0);
      v19 = a1[681];
      v24 = (_DWORD *)a1[680];
      v20 = a1[682];
      v25 = v19;
      v21 = a1[683];
      v26 = v20;
      v27 = v21;
      sub_59CBF0();
    }
  }
  sub_5A6EC0(v33);
  if ( sub_5A4330(a1) == 3 && sub_6442E0(v10) == 2 )
  {
    htonl(0);
    htons(0);
    v22 = a1[683];
    v24 = (_DWORD *)a1[682];
    v25 = v22;
    sub_59CBF0();
  }
  if ( *(_DWORD *)(v31 + 16) )
    ReleaseMutex(*(HANDLE *)(v31 + 16));
  v30[0] = -1;
  sub_5A6D70(&v24);
  return 0;
}
