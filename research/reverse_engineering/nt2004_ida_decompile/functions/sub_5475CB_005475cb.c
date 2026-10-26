int __thiscall sub_5475CB(int this, int a2)
{
  unsigned int v3; // ecx
  int v4; // ebx
  void *v5; // eax
  void *v6; // eax
  void *v8; // [esp+10h] [ebp-10h]

  sub_54429C((float *)this, (float *)a2, 0, 1);
  v3 = *(_DWORD *)(this + 4144) & 0xFFFFFFFE;
  v4 = ((*(_DWORD *)(this + 4152) + 1) & 0xFFFFFFFE) - v3;
  *(_DWORD *)(this + 4216) = (*(_DWORD *)(this + 4152) + 1) & 0xFFFFFFFE;
  *(_DWORD *)this = &off_5F314C;
  *(_DWORD *)(this + 4208) = v3;
  *(_DWORD *)(this + 4212) = 0;
  *(_DWORD *)(this + 4224) = 0;
  *(_DWORD *)(this + 4220) = 0;
  *(_DWORD *)(this + 4228) = 0;
  *(_DWORD *)(this + 4232) = v4;
  *(_DWORD *)(this + 4236) = 0;
  *(_DWORD *)(this + 4240) = 1;
  v5 = operator new(16 * v4);
  v8 = v5;
  if ( v5 )
  {
    sub_53D688((int)v5, 16, v4, (int (__thiscall *)(int))sub_53D5B2);
    v6 = v8;
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)(this + 4204) = v6;
  if ( !v6 )
    *(_DWORD *)(this + 4240) = 0;
  if ( *(_DWORD *)(a2 + 4) == 1498831189 )
  {
    *(_DWORD *)(this + 4244) = 8;
    *(_DWORD *)(this + 4248) = 0;
  }
  else
  {
    *(_DWORD *)(this + 4244) = 0;
    *(_DWORD *)(this + 4248) = 8;
  }
  return this;
}
