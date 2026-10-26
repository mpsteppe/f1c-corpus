int __usercall sub_553C0E@<eax>(int a1@<esi>)
{
  int v1; // edi
  int v2; // ecx
  char v3; // al
  int result; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // [esp+0h] [ebp-10h]
  char v8; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 380);
  sub_5539B0(v7);
  sub_553B9F(a1);
  *(_DWORD *)(v1 + 12) = 0;
  *(_BYTE *)(v1 + 16) = sub_55393F(v2, a1);
  *(_DWORD *)(v1 + 20) = 0;
  *(_DWORD *)(v1 + 24) = 0;
  v3 = *(_BYTE *)(a1 + 74);
  if ( !v3 || !*(_BYTE *)(a1 + 64) )
  {
    *(_BYTE *)(a1 + 88) = 0;
    *(_BYTE *)(a1 + 89) = 0;
    *(_BYTE *)(a1 + 90) = 0;
  }
  if ( v3 )
  {
    if ( *(_BYTE *)(a1 + 65) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 46;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_DWORD *)(a1 + 100) == 3 )
    {
      if ( *(_DWORD *)(a1 + 116) )
      {
        *(_BYTE *)(a1 + 89) = 1;
        goto LABEL_10;
      }
      if ( *(_BYTE *)(a1 + 80) )
      {
        *(_BYTE *)(a1 + 90) = 1;
        goto LABEL_10;
      }
    }
    else
    {
      *(_BYTE *)(a1 + 89) = 0;
      *(_BYTE *)(a1 + 90) = 0;
      *(_DWORD *)(a1 + 116) = 0;
    }
    *(_BYTE *)(a1 + 88) = 1;
LABEL_10:
    if ( *(_BYTE *)(a1 + 88) )
    {
      sub_55BAFC(a1);
      *(_DWORD *)(v1 + 20) = *(_DWORD *)(a1 + 420);
    }
    if ( *(_BYTE *)(a1 + 90) || *(_BYTE *)(a1 + 89) )
    {
      sub_55B06A(a1);
      *(_DWORD *)(v1 + 24) = *(_DWORD *)(a1 + 420);
    }
  }
  if ( !*(_BYTE *)(a1 + 65) )
  {
    if ( *(_BYTE *)(v1 + 16) )
    {
      sub_55A0F5(a1);
    }
    else
    {
      sub_559AFC(a1);
      sub_559371(a1);
    }
    sub_558EB2(a1, *(_BYTE *)(a1 + 90));
  }
  sub_558C17(a1);
  if ( *(_BYTE *)(a1 + 201) )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 1;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  else if ( *(_BYTE *)(a1 + 200) )
  {
    sub_5589FF(a1);
  }
  else
  {
    sub_557E51(a1);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 396) + 16) || (v8 = 0, *(_BYTE *)(a1 + 64)) )
    v8 = 1;
  sub_557481(a1, v8);
  if ( !*(_BYTE *)(a1 + 65) )
    sub_556842(a1, 0);
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 24))(a1);
  result = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 396) + 8))(a1);
  v5 = *(_DWORD *)(a1 + 8);
  if ( v5 )
  {
    if ( !*(_BYTE *)(a1 + 64) )
    {
      result = *(_DWORD *)(a1 + 396);
      if ( *(_BYTE *)(result + 16) )
      {
        v6 = *(_DWORD *)(a1 + 32);
        if ( *(_BYTE *)(a1 + 200) )
          v6 = 3 * v6 + 2;
        *(_DWORD *)(v5 + 4) = 0;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = v6 * *(_DWORD *)(a1 + 280);
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 12) = 0;
        result = (*(_BYTE *)(a1 + 90) != 0) + 2;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 16) = result;
        ++*(_DWORD *)(v1 + 12);
      }
    }
  }
  return result;
}
