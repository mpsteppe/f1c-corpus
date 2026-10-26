int __stdcall sub_5598B0(int a1, const char *a2, const char *a3)
{
  _DWORD *v3; // esi
  int v4; // edi
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // esi
  _DWORD *v9; // ebx
  _DWORD *v10; // eax
  int i; // eax
  _DWORD *v12; // eax
  _BYTE v13[256]; // [esp+Ch] [ebp-100h] BYREF

  v3 = (_DWORD *)dword_8B8F2C;
  if ( dword_8B8F2C )
  {
    v4 = UTF16StringSearchInLinkedList((int *)dword_8B8F2C, a2);
    if ( v4 )
    {
      v6 = BinaryTreeSearch(v3, a3);
      if ( v6 )
      {
        v7 = LinkedListNodeSearchAllocation(v3, v4, v6);
        v8 = *(_DWORD *)(a1 + 548);
        v9 = v7;
        if ( v8 )
        {
          for ( i = *(_DWORD *)(v8 + 4); i; i = *(_DWORD *)(i + 4) )
            v8 = i;
          v12 = (_DWORD *)OperatorNewNhMallocWrapper(8);
          *(_DWORD *)(v8 + 4) = v12;
          *v12 = v9;
          v12[1] = 0;
          return 0;
        }
        else
        {
          v10 = (_DWORD *)OperatorNewNhMallocWrapper(8);
          *(_DWORD *)(a1 + 548) = v10;
          *v10 = v9;
          *(_DWORD *)(*(_DWORD *)(a1 + 548) + 4) = 0;
          return 0;
        }
      }
      else
      {
        StringFormatWithBufferOverflowCheck(v13, "Could not find resposne %s", a3);
        return -1;
      }
    }
    else
    {
      StringFormatWithBufferOverflowCheck(v13, "Could not find actor %s", a2);
      return -1;
    }
  }
  else
  {
    sub_53C590(-1, aCouldNotFindRe);
    return -1;
  }
}
