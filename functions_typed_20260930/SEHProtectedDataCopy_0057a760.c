int __thiscall sub_57A760(ULONG_PTR *this, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // esi
  ULONG_PTR v6; // ecx
  int v7; // eax
  int v9; // [esp+8h] [ebp-64h] BYREF
  int v10[21]; // [esp+Ch] [ebp-60h] BYREF
  int v11; // [esp+68h] [ebp-4h]

  v5 = 11;
  SEHProtectedDirectXRenderStateSetup(v10);
  v6 = *this;
  v11 = 0;
  if ( (unsigned __int8)sub_5853B0(v6, (int)v10) )
  {
    v9 = 0;
    BoundedMemoryCopyWithSizeValidation(a2, *a3, &v9);
    v7 = v9;
    *a4 = v10[1];
    *a3 = v7;
    v5 = 0;
  }
  v11 = -1;
  SEHGuardedFunctionWithExceptionHandling(v10);
  return v5;
}

