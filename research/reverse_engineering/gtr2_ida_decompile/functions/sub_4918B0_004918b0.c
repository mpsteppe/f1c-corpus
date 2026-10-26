char __thiscall sub_4918B0(_DWORD *this, int a2)
{
  int v3; // edx
  char result; // al

  v3 = *this;
  this[210] = a2;
  (*(void (**)(void))(v3 + 184))();
  (*(void (__thiscall **)(_DWORD *, int))(*this + 40))(this, 1);
  result = sub_4735E0(&dword_B6CBA8);
  if ( result )
  {
    result = *((_BYTE *)this + 844);
    if ( result )
      result = sub_478CF0();
  }
  *((_BYTE *)this + 844) = 0;
  return result;
}
