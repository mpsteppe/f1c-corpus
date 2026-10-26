_WORD *__fastcall sub_62E530(int a1, _BYTE *a2, int a3, int a4)
{
  _WORD *result; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  char v12; // bl
  int v13; // edx
  int v14; // edx

  if ( *(int *)(a1 + 122) <= 0 )
  {
    if ( a3 + 4 <= (unsigned int)(a3 + 5) && a2 )
    {
      v6 = a4;
      sub_62E2A0(a1, a2, a3, a4);
    }
    else
    {
      v6 = a4;
      v8 = *(_DWORD *)(a1 + 5805);
      v9 = a4 + 2;
      if ( v8 <= 13 )
      {
        *(_WORD *)(a1 + 5803) |= v9 << v8;
        *(_DWORD *)(a1 + 5805) = v8 + 3;
      }
      else
      {
        v10 = v9 << v8;
        v11 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5803) |= v10;
        *(_BYTE *)(v11 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5803);
        v12 = *(_BYTE *)(a1 + 5804);
        v13 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v13;
        *(_BYTE *)(v13 + *(_DWORD *)(a1 + 8)) = v12;
        v14 = *(_DWORD *)(a1 + 5805);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5805) = v14 - 13;
        *(_WORD *)(a1 + 5803) = (unsigned __int16)v9 >> (16 - v14);
      }
      sub_62D910(a1, (int)&unk_72F458, (int)&unk_72F8D8);
    }
    result = sub_62CD30(v7, a1);
    if ( v6 )
      return (_WORD *)sub_62DE50(a1);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 28) == 2 )
      sub_62DD40(a1);
    return (_WORD *)off_16C98CC(a3, a4);
  }
  return result;
}
