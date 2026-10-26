// Address: 0x0048741b
// Size: 69 bytes
// Name: sub_48741B
// Type: int __userpurge@<eax>(char@<bl>, _DWORD *@<esi>, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
int __userpurge sub_48741B@<eax>(char a1@<bl>, _DWORD *a2@<esi>, int a3)
{
  int result; // eax
  int v4; // eax
  int v5; // esi
  int v6; // [esp-4h] [ebp-4h]

  sub_486660(v6);
  if ( a1 )
  {
    result = (*(int (__thiscall **)(_DWORD *, int))(*a2 + 64))(a2, 4);
  }
  else
  {
    v4 = ((int (__thiscall *)(_DWORD *))sub_487740)(a2);
    result = sub_487330(v4);
  }
  v5 = a2[36];
  if ( v5 )
  {
    do
    {
      (*(void (__thiscall **)(int, char))(*(_DWORD *)v5 + 56))(v5, a1);
      result = sub_486320(v5);
      v5 = result;
    }
    while ( result );
  }
  return result;
}
