// f1c  0x004c94d0  size=43
int __thiscall sub_4C94D0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // edi
  int result; // eax

  v1 = this + 7;
  v2 = 3;
  do
  {
    if ( *v1 )
    {
      result = (**(int (__thiscall ***)(_DWORD, int))*v1)(*v1, 1);
      *v1 = 0;
    }
    ++v1;
    --v2;
  }
  while ( v2 );
  return result;
}
