int __stdcall ShortComputation_5050(int a1, int *a2)
{
  _DWORD *v2; // eax
  int v3; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-8h]

  v2 = OneTimeInitializationWithAtexitStyleRegistration();
  v3 = ResourceIDLookupByNameString(v2, (const char *)a1);
  if ( v3 == -1 )
  {
    if ( a1
      && strlen((const char *)a1) >= 5
      && sub_566810((_BYTE *)a1, asc_5BE820)
      && (v8 = SingleFunctionCallWrapper_7f59((unsigned __int8 *)(a1 + 4)),
          v5 = OneTimeInitializationWithAtexitStyleRegistration(),
          (v6 = ResourceNodeLookupByStringOrID(v5, 0, v8)) != 0) )
    {
      *a2 = *(_DWORD *)(v6 + 16);
      return 1;
    }
    else
    {
      v7 = StringFormatWith0x40Size((LPCSTR)a1, 0x8000, 256);
      if ( v7 == -1 )
      {
        return 0;
      }
      else
      {
        *a2 = v7;
        return 1;
      }
    }
  }
  else
  {
    *a2 = v3;
    return 1;
  }
}
