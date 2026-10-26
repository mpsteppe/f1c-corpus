int __thiscall sub_42AF40(_BYTE *this)
{
  int result; // eax

  PitStateChangeRequest(0);
  result = ConditionalGate(this + 12);
  this[17424] = 1;
  this[17908] = 0;
  return result;
}

