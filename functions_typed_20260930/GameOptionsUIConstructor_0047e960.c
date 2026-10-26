_DWORD *__thiscall GameOptionsUIConstructor(_DWORD *this, int a2)
{
  int v3; // edi
  LPVOID **v4; // ebx
  char v5; // al
  LPVOID *v6; // ebp
  _DWORD *result; // eax

  ConstructorInitVTable((int)this, 1, -1);
  this[59] = 0;
  this[60] = -1;
  *this = &off_5A6C78;
  v3 = this[17];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        if ( *v6 )
          FreeWrapper_7bcf(*v6);
        FreeWrapper_7bcf(v6);
      }
    }
    FreeWrapper_7bcf(v4);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[61] = a2;
  switch ( a2 )
  {
    case 484:
    case 485:
    case 486:
    case 487:
    case 488:
    case 489:
    case 490:
    case 491:
    case 492:
    case 493:
    case 494:
      LinkedListInsertWithNodeAllocation(this, (int)aAllowed, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aDisallowed, -1);
      result = this;
      break;
    case 498:
      LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
      result = this;
      break;
    case 499:
    case 500:
      LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aNormal_0, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aX2, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aX3, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aX4, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aX5, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aX6, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aX7, -1);
      result = this;
      break;
    case 501:
      LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aNormal_0, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aTimeScaled, -1);
      LinkedListInsertWithNodeAllocation(this, (int)aSelectedSeason, -1);
      goto LABEL_13;
    default:
LABEL_13:
      result = this;
      break;
  }
  return result;
}

