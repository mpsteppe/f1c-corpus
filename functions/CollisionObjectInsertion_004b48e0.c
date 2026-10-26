char __thiscall sub_4B48E0(_BYTE *this, _DWORD *a2, int a3)
{
  int v3; // ebp
  _DWORD *v4; // edi
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // edx
  int v10; // [esp-8h] [ebp-18h]

  if ( !*this )
    return 0;
  switch ( *a2 >> 29 )
  {
    case 1:
      v3 = 0;
      break;
    case 2:
    case 3:
      v3 = 1;
      break;
    case 4:
      v3 = 2;
      break;
    case 6:
      v3 = 3;
      break;
    default:
      v3 = -1;
      break;
  }
  if ( ArithmeticComparison_4760(v3, a2) )
    return 0;
  v4 = 0;
  ShortComputation_a780(&dword_8AB700);
  if ( dword_8AB708 )
  {
    v4 = *(_DWORD **)dword_8AB708;
    v10 = *(_DWORD *)dword_8AB708;
    *(_BYTE *)(dword_8AB708 + 8) = 0;
    if ( !(unsigned __int8)sub_4BB6B0(v10, 1) )
      v4 = 0;
  }
  if ( !v4 )
  {
    if ( OperatorNewNhMallocWrapper(4) )
      v5 = ConditionalAllocation(0);
    else
      v5 = 0;
    LinkedListNodeInsertion_ac40(v5, 0);
    v4 = (_DWORD *)LinkedListNodeRemoval_acf0(&dword_8AB700);
  }
  ArithmeticComparison_3a90(v4, a2);
  v6 = &this[16 * v3 + 112];
  if ( !v4 )
    return 0;
  v7 = OperatorNewNhMallocWrapper(12);
  if ( v7 )
  {
    *(_DWORD *)v7 = v4;
    *(_DWORD *)(v7 + 4) = 0;
    *(_BYTE *)(v7 + 8) = 0;
  }
  else
  {
    v7 = 0;
  }
  if ( *v6 )
  {
    v8 = v6[1];
    *(_DWORD *)(v8 + 4) = v7;
  }
  else
  {
    *v6 = v7;
    v6[2] = v7;
  }
  v6[1] = v7;
  ++v6[3];
  ArithmeticComparison_47a0((int)this, v8, 1, v3, (unsigned __int8)*v4);
  return 1;
}
