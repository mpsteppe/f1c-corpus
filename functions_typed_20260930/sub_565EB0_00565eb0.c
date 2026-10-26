LPVOID ***__thiscall sub_565EB0(LPVOID ****this)
{
  LPVOID ***result; // eax

  EnhancedListCleanupWithSubObjectDelete(*this);
  result = *this;
  (*this)[135] = 0;
  return result;
}

