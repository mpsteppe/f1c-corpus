const char *__thiscall sub_45C0C0(int this, LPCSTR lpFileName, const char *a3, int a4)
{
  const char *result; // eax
  char v6; // al
  char *v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // ebp
  int v11; // eax
  int v12; // [esp+10h] [ebp-204h] BYREF
  char v13[512]; // [esp+14h] [ebp-200h] BYREF

  sub_565F80(lpFileName, 1, (int)a3, 1);
  LinkedListPopFront_5f50(&unk_8AD3B0);
  for ( result = (const char *)DirectoryEntryIterator(&unk_8AD3B0);
        result;
        result = (const char *)DirectoryEntryIterator(&unk_8AD3B0) )
  {
    StringFormatWithBufferOverflowCheck(v13, "%s%s", a3, result);
    if ( a4 == 1 )
    {
      v6 = sub_45C400(v13, &v12);
    }
    else if ( a4 == 2 )
    {
      v6 = DataFileCheckSizeQuery(v13, &v12);
    }
    else
    {
      v6 = UtilityFunction_8a60(*(unsigned __int8 *)(this + 1), &v12);
    }
    if ( v6 )
    {
      v7 = &v13[strlen(v13)];
      if ( v7 > v13 )
      {
        while ( *v7 != 92 )
        {
          if ( --v7 <= v13 )
            goto LABEL_13;
        }
        ++v7;
      }
LABEL_13:
      v8 = (_DWORD *)OperatorNewNhMallocWrapper(12);
      v9 = v8;
      if ( v8 )
      {
        v10 = v12;
        *v8 = 0;
        v8[1] = -1;
        StringCopyWithBufferRealloc(v7);
        v9[2] = v10;
      }
      else
      {
        v9 = 0;
      }
      if ( v9 )
      {
        v11 = OperatorNewNhMallocWrapper(12);
        if ( v11 )
        {
          *(_DWORD *)v11 = v9;
          *(_DWORD *)(v11 + 4) = 0;
          *(_BYTE *)(v11 + 8) = 1;
        }
        else
        {
          v11 = 0;
        }
        if ( *(_DWORD *)(this + 4) )
        {
          *(_DWORD *)(*(_DWORD *)(this + 8) + 4) = v11;
        }
        else
        {
          *(_DWORD *)(this + 4) = v11;
          *(_DWORD *)(this + 12) = v11;
        }
        *(_DWORD *)(this + 8) = v11;
        ++*(_DWORD *)(this + 16);
      }
    }
    result = (const char *)LinkedListNodePeek(&unk_8AD3B0);
    if ( !(_BYTE)result )
      break;
  }
  return result;
}
