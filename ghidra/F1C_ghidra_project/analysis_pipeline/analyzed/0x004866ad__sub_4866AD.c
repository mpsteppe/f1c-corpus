// Address: 0x004866ad
// Size: 46 bytes
// Name: sub_4866AD
// Type: int __userpurge@<eax>(char@<bl>, int@<esi>, int)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_4866AD@<eax>(char a1@<bl>, int a2@<esi>, int a3)
{
  int result; // eax
  int v4; // esi

  result = (*(int (__cdecl **)(int))(*(_DWORD *)a2 + 44))(1);
  *(_BYTE *)(a2 + 101) = a1;
  v4 = *(_DWORD *)(a2 + 144);
  if ( v4 )
  {
    do
    {
      (*(void (__thiscall **)(int, char))(*(_DWORD *)v4 + 60))(v4, a1);
      result = sub_486320(v4);
      v4 = result;
    }
    while ( result );
  }
  return result;
}
