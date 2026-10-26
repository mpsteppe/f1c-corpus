int __stdcall MemoryAllocation_5160(int a1, LONG a2, int a3)
{
  int v3; // esi
  unsigned __int16 v4; // bx
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v10; // eax
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v4 = 1;
      goto LABEL_7;
    }
    if ( a3 == 2 )
    {
      v4 = 2;
      goto LABEL_7;
    }
  }
  v4 = 0;
LABEL_7:
  a3 = 0;
  v11 = 0;
  v5 = OneTimeInitializationWithAtexitStyleRegistration();
  v6 = ResourceNodeLookupByStringOrID(v5, 0, a1);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 40);
    a3 = v7;
    v11 = *(_DWORD *)(v6 + 36);
  }
  else
  {
    OneTimeInitializationWithAtexitStyleRegistration();
    if ( !(unsigned __int8)LinkedListSearchByID(a1) )
      return sub_58C724(a1, a2, v4);
    OneTimeInitializationWithAtexitStyleRegistration();
    if ( !(unsigned __int8)LinkedListNodeSearchByIDOperation(a1, &a3, &v11) )
      return sub_58C724(a1, a2, v4);
    v7 = a3;
  }
  if ( v4 )
  {
    if ( v4 != 1 )
    {
      if ( v4 == 2 && !a2 )
      {
        v8 = sub_58C724(a1, v7 + v11, 0);
        v3 = v8;
        if ( v8 != 1 )
          return v8 - a3;
      }
      return v3;
    }
    v10 = sub_58C724(a1, a2, 1u);
  }
  else
  {
    v10 = sub_58C724(a1, a2 + v7, 0);
  }
  v3 = v10;
  if ( v10 != 1 )
    return v10 - a3;
  return v3;
}
