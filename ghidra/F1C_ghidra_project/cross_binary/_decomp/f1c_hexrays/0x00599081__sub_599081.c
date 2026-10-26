// f1c  0x00599081  size=45
int __thiscall sub_599081(int *this)
{
  unsigned __int8 *v2; // eax
  int v4; // edi
  int v5; // eax

  v2 = *(unsigned __int8 **)this[7];
  if ( v2 && v2 < &v2[*(_DWORD *)this[11]] )
    return *v2;
  v4 = *this;
  v5 = (*(int (__thiscall **)(int *))(*this + 20))(this);
  return (*(int (__thiscall **)(int *, int))(v4 + 8))(this, v5);
}
