int __thiscall sub_529C70(void *this)
{
  char *v2; // edi
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // eax
  int result; // eax
  int v8; // [esp-Ch] [ebp-120h]
  int v9; // [esp+0h] [ebp-114h]
  int v10; // [esp+0h] [ebp-114h]
  _BYTE v11[3]; // [esp+Ch] [ebp-108h] BYREF
  char v12; // [esp+Fh] [ebp-105h] BYREF
  char v13[260]; // [esp+10h] [ebp-104h] BYREF

  v2 = &v12;
  strcpy(v13, "?|");
  while ( *++v2 )
    ;
  strcpy(v2, "__new.tmp");
  *(_DWORD *)(*((_DWORD *)this + 6) + 2892924) = 1;
  sub_615860(v13);
  sub_53F190(&unk_92B550, 0, v9);
  if ( (unsigned __int8)sub_528A30(*((int **)this + 6), 1, (int)v11, 0) )
  {
    *(_DWORD *)(*((_DWORD *)this + 6) + 2892972) = 5;
    *(_BYTE *)(*((_DWORD *)this + 6) + 2892960) = 1;
    v4 = *((_DWORD *)this + 6);
    v5 = (_DWORD *)((char *)&unk_9204A0 + 22616 * *(_DWORD *)(v4 + 2892924));
    v5[4859] = *(_DWORD *)(v4 + 2893232);
    v5[4862] = *(_DWORD *)(*((_DWORD *)this + 6) + 2893232);
    v5[4860] = *(_DWORD *)(*((_DWORD *)this + 6) + 2893236);
    v5[4863] = *(_DWORD *)(*((_DWORD *)this + 6) + 2893236);
    v5[4861] = *(_DWORD *)(*((_DWORD *)this + 6) + 2893240);
    v5[4864] = *(_DWORD *)(*((_DWORD *)this + 6) + 2893240);
    v5[4821] = 0;
    v5[4822] = 0;
    sub_53F0E0(0);
    sub_53F190(v5, 1, v8);
    v6 = *((_DWORD *)this + 6);
    *(_DWORD *)this = 2;
    *((_BYTE *)this + 9) = 0;
    v10 = *(int *)(v6 + 2892844);
    *(float *)(v6 + 2892856) = *(float *)&v10;
    sub_522980(*((void **)this + 6), v10);
  }
  else
  {
    *(_DWORD *)this = 0;
    *((_BYTE *)this + 9) = 0;
  }
  if ( byte_B731E0 )
  {
    result = sub_524780(*((_DWORD **)this + 6));
    *((_DWORD *)this + 5) = 1;
  }
  else
  {
    result = sub_546C00(&unk_BE2728, 12);
    *((_DWORD *)this + 5) = 0;
  }
  return result;
}
