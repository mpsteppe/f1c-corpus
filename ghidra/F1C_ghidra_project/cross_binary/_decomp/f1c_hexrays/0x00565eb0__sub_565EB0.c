// f1c  0x00565eb0  size=24
LPVOID ***__thiscall sub_565EB0(LPVOID ****this)
{
  LPVOID ***result; // eax

  sub_565D50(*this);
  result = *this;
  (*this)[135] = 0;
  return result;
}
