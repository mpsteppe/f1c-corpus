void __thiscall sub_5BDA60(int this)
{
  int v2; // ebx
  int i; // esi
  int *v4; // eax

  v2 = sub_577650(*(void **)(this + 4));
  for ( i = 0; i < v2; ++i )
  {
    v4 = (int *)sub_5BE1B0(*(_DWORD *)(this + 4), i);
    sub_5BD9E0(this, *v4);
  }
  sub_5BE3D0(*(_DWORD *)(this + 4));
  sub_5BDA20((_DWORD *)this);
}
