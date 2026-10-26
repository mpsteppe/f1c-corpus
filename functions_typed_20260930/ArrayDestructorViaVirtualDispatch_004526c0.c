int __thiscall sub_4526C0(int *this)
{
  int *v1; // esi
  int v2; // edi
  int result; // eax

  this[261] = 0;
  v1 = this + 25;
  v2 = 10;
  do
  {
    result = *v1;
    if ( *v1 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)result + 44))(*v1);
      result = (*(int (__stdcall **)(int))(*(_DWORD *)*v1 + 8))(*v1);
      *v1 = 0;
    }
    v1 += 26;
    --v2;
  }
  while ( v2 );
  return result;
}

