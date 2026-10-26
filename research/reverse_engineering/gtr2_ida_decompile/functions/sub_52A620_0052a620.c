char __userpurge sub_52A620@<al>(int a1@<ecx>, const char *a2@<ebp>, int a3, int a4, int a5)
{
  char v6; // bl
  CHAR *v7; // edi
  char *v8; // eax
  int i; // eax
  int v10; // edx
  int v11; // eax
  double v12; // st7
  void *Block; // [esp+0h] [ebp-4ECh]
  int v15; // [esp+8h] [ebp-4E4h]
  _DWORD v16[2]; // [esp+Ch] [ebp-4E0h] BYREF
  char *Str1; // [esp+1Ch] [ebp-4D0h]
  int v18; // [esp+20h] [ebp-4CCh]
  _BYTE v19[64]; // [esp+28h] [ebp-4C4h] BYREF
  _BYTE v20[8]; // [esp+68h] [ebp-484h] BYREF
  _BYTE v21[20]; // [esp+70h] [ebp-47Ch] BYREF
  _BYTE v22[72]; // [esp+84h] [ebp-468h] BYREF
  _BYTE v23[1016]; // [esp+CCh] [ebp-420h] BYREF
  int v24; // [esp+4CCh] [ebp-20h]
  float v25; // [esp+4D8h] [ebp-14h]
  int v26; // [esp+4E0h] [ebp-Ch]
  int v27; // [esp+4E8h] [ebp-4h]

  sub_615860(a3);
  v6 = 0;
  sub_613B30(v19);
  v27 = 0;
  if ( !(unsigned __int8)sub_614460(a3, 0) )
    goto LABEL_19;
  Str1 = (char *)operator new(0x80u);
  *Str1 = 0;
  v18 = 128;
  LOBYTE(v27) = 1;
  sub_615860(Str2);
  sub_615A50("__ds.tmp");
  v7 = Str1;
  if ( !Str1 )
    v7 = (CHAR *)WindowName;
  if ( !strncmp(v7, Str2, 2u) )
    sub_614A60(v7);
  else
    sub_617680(v7);
  sub_613B30(v22);
  v8 = Str1;
  LOBYTE(v27) = 2;
  if ( !Str1 )
    v8 = (char *)WindowName;
  v16[0] = 1;
  if ( (unsigned __int8)sub_6146B0(v8, 0, 0) )
  {
    for ( i = sub_613CE0(v23, 1024); i > 0; i = sub_613CE0(v23, 1024) )
      sub_613C90(v23, i);
    sub_613C30(v21);
    v6 = sub_528A30(*(int **)(a1 + 4), (int)v7, 1, 0);
    if ( v6 )
    {
      *(_DWORD *)(*(_DWORD *)(a1 + 4) + 2892972) = 6;
      *(_BYTE *)(*(_DWORD *)(a1 + 4) + 2892960) = 1;
      sub_522DB0();
      v10 = *(_DWORD *)(a1 + 4);
      if ( (_UNKNOWN *)((char *)&unk_9204A0 + 22616 * *(_DWORD *)(v10 + 2892924)) )
      {
        sub_53E6A0((char *)&unk_9204A0 + 22616 * *(_DWORD *)(v10 + 2892924), 4);
        sub_53F0E0(v26);
      }
    }
    else
    {
      sub_520820((char *)1, a2);
    }
  }
  sub_613C30(v16);
  LOBYTE(v24) = 1;
  sub_614140(v20);
  LOBYTE(v24) = 0;
  if ( Block )
    j_j__free(Block);
  if ( v6 )
  {
    v11 = *(_DWORD *)(a1 + 4);
    v12 = v25;
    *(_DWORD *)a1 = 2;
    *(float *)&v15 = v12 + *(float *)(v11 + 2892844);
    *(float *)(v11 + 2892856) = *(float *)&v15;
    sub_522980(*(void **)(a1 + 4), v15);
  }
  else
  {
LABEL_19:
    *(_DWORD *)a1 = 0;
  }
  v24 = -1;
  sub_614140(v16);
  return v6;
}
