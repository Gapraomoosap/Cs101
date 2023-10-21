package year2.OOP.lab6.lab6_8;

public static boolean contains(Line a, Rectangle b) {
        return b.contains(a.getStart().getX(), a.getStart().getY()) &&
                b.contains(a.getEnd().getX(), a.getEnd().getY());
    }

    // Not collinear
    public static boolean cross(Line a, Line b) {
        return (a.getStart().getX() - a.getEnd().getX()) * (b.getStart().getY() - b.getEnd().getY()) -
                (a.getStart().getY() - a.getEnd().getY()) * (b.getStart().getX() - b.getEnd().getX()) != 0;
    }

    public static boolean overlaps(Rectangle a, Rectangle b) {
        return a.overlaps(b);
    }

    public static double distance(Line a, Rectangle b) {
        return Math.sqrt(Math.pow(a.getEnd().getX() - b.getOrigin().getX(), 2)
                + Math.pow(a.getEnd().getY() - b.getOrigin().getY(), 2));
    }