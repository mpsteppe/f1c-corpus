int __thiscall sub_451C00(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // ebx
  int v10; // ecx
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  bool v15; // cc

  result = a4;
  switch ( a4 )
  {
    case 0:
      result = a5;
      this[44] = a5;
      break;
    case 1:
      this[45] = a5;
      break;
    case 2:
      this[46] = a5;
      break;
    case 3:
      result = a5;
      this[47] += a5;
      break;
    default:
      result = a2 - this[4];
      v7 = a3 - this[5];
      if ( a2 != this[4] || v7 )
      {
        if ( *((_BYTE *)this + 192) )
        {
          v8 = this[7];
          this[6] += result;
          v9 = v7 + v8;
          v10 = *this;
          this[4] = (this[3] + this[2] + 1) / 2;
          this[5] = (this[1] + v10 + 1) / 2;
          this[7] = v9;
          result = SetCursorPos((Rect.right + Rect.left) / 2, (Rect.bottom + Rect.top) / 2);
        }
        else
        {
          v11 = result + this[6];
          v12 = this[2];
          this[6] = v11;
          this[7] += v7;
          this[4] = a2;
          if ( a2 < v12 )
            this[4] = v12;
          v13 = this[3];
          if ( this[4] > v13 )
            this[4] = v13;
          v14 = *this;
          v15 = a3 < *this;
          this[5] = a3;
          if ( v15 )
            this[5] = v14;
          result = this[1];
          if ( this[5] > result )
            this[5] = result;
        }
        *((float *)this + 10) = (double)(int)this[4] * *((float *)this + 8);
        *((float *)this + 11) = (double)(int)this[5] * *((float *)this + 9);
      }
      break;
  }
  return result;
}
