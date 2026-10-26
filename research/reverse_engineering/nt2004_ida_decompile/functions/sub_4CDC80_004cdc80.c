int __thiscall sub_4CDC80(int this, int a2)
{
  CHAR *v3; // ecx
  char v4; // si
  int v6[7]; // [esp+Ch] [ebp-21Ch] BYREF
  char NewFilename[256]; // [esp+28h] [ebp-200h] BYREF
  char FileName[253]; // [esp+128h] [ebp-100h] BYREF
  __int16 v9; // [esp+225h] [ebp-3h]
  char v10; // [esp+227h] [ebp-1h]

  if ( !sub_4634F0(dword_764D70) || dword_75CBA8 == 1 )
  {
    sub_57B040((char *)(this + 20), 256);
    sub_578600(NewFilename);
    v3 = &byte_629120 + strlen(&byte_629120);
    if ( v3 > &byte_629120 )
    {
      while ( *v3 != 46 )
      {
        if ( --v3 <= &byte_629120 )
          goto LABEL_8;
      }
      *v3 = 0;
    }
LABEL_8:
    sub_578560(aTmp);
    _chmod(NewFilename, 384);
    _chmod(&byte_629120, 384);
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_13, 1959) )
      sub_500FE0((int)&unk_7D7920, aAttemptingToSa, (char)&byte_629120);
    sub_57A080(v6);
    sub_57A110(&byte_629120, 0, 1, 1);
    if ( v6[0] )
      sub_4BC450((int *)this, (int)v6, asc_60F778);
    sub_57A360(v6);
    FileName[0] = byte_629120;
    memset(&FileName[1], 0, 0xFCu);
    v9 = 0;
    v10 = 0;
    sub_4CD760((char *)this, FileName, 256);
    _chmod(FileName, 384);
    sub_4E5C50(FileName);
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 22340) + 20))(*(_DWORD *)(this + 22340));
    sub_435E80(&dword_75E8F0, this);
    remove(NewFilename);
    v4 = rename(&byte_629120, NewFilename);
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_13, 1989) )
      sub_500FE0((int)&unk_7D7920, aRetcodeDForRen, v4);
    sub_57A0A0(v6);
  }
  return 0;
}
