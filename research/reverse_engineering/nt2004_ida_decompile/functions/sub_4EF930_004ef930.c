void __userpurge sub_4EF930(int a1@<ecx>, int a2@<esi>, char *FileName)
{
  int v4; // ecx
  int v5; // [esp+10h] [ebp-38h]
  _DWORD v6[2]; // [esp+14h] [ebp-34h] BYREF
  int v7; // [esp+1Ch] [ebp-2Ch]
  int v8; // [esp+20h] [ebp-28h]
  char v9; // [esp+24h] [ebp-24h]
  _BYTE v10[32]; // [esp+28h] [ebp-20h] BYREF

  v4 = dword_7D6BB4;
  if ( dword_7D6BB4
    || dword_7D6BB0
    && (dword_7D6BB4 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_7D6BB0 + 100))(dword_7D6BB0),
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_7D6BB4 + 32))(dword_7D6BB4, LODWORD(flt_767898)),
        (v4 = dword_7D6BB4) != 0) )
  {
    if ( FileName )
    {
      if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 8))(v4, a2) )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_7D6BB4 + 12))(dword_7D6BB4);
      v6[0] = 0;
      v6[1] = -1;
      sub_578600(&byte_629120);
      v7 = -1;
      v8 = -1;
      v9 = 0;
      sub_578600(FileName);
      if ( sub_579060(FileName, aDjs) && !_stat(FileName, (struct _stat32 *const)v10) )
      {
        v7 = 0;
        v8 = *(_DWORD *)&v10[20];
        v9 = 1;
      }
      (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)dword_7D6BB4 + 4))(dword_7D6BB4, v6, 1);
      sub_578600(FileName);
      if ( v5 )
        sub_5BE8AE();
    }
    else
    {
      sub_578600(&byte_629120);
    }
    *(_BYTE *)(a1 + 20) = 1;
    *(_DWORD *)(a1 + 24) = 0;
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_7D6BB4 + 32))(dword_7D6BB4, LODWORD(flt_767898));
  }
}
