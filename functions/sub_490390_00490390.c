int __thiscall sub_490390(_DWORD *this)
{
  switch ( ShortComputation_6720(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4);
      break;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 1);
      break;
    default:
      break;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 156))(this);
  VTableDispatchListIteration(this);
  return 0;
}
