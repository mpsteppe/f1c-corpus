int __thiscall sub_65B31F(_DWORD *this)
{
  int result; // eax

  sub_659BB5();
  this[169] = 1;
  result = dword_FB9E44;
  dword_FB9E44 = (int)this;
  this[170] = result;
  return result;
}
