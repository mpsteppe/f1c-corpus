void __thiscall sub_43B930(void *this, int a2, double a3)
{
  switch ( a2 )
  {
    case 3:
      DeltaUpdateTracking(a3);
      break;
    case 9:
      QuadraticSpringEval((int)this + 6200, a3);
      break;
    case 10:
      QuadraticSpringEval((int)this + 6300, a3);
      break;
    case 14:
      ConstraintForceSolver(a3);
      break;
    case 27:
      QuadFunctionEval(a3);
      break;
    case 28:
      QuadraticForceTorqueCalculator(a3);
      break;
    case 29:
      SpringDamperCompute(a3);
      break;
    default:
      return;
  }
}

