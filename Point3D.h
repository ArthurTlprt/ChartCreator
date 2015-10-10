#ifndef POINT3D_H
#define	POINT3D_H

class Point3D{
	private:
	float x,y,z;
	static int count;
	
	public:
	Point3D();
	Point3D(float,float,float);
	Point3D(const Point3D &);
	void reset(); //remet le point sur (0,0,0)
	float moveTo(const Point3D&); //déplacement vers un point_retourne la distance parcourue
	float moveTo(float,float=0,float=0); //déplacement d'une distance_retourne la distance parcourue
	void decr(); //décrémente toutes les coordonnées à -1
	void incr(); //incrémente toutes les coordonnées à +1
	void print() const; //affiche un point sous la forme (x,y,z) - couleur
	const float & getX() const;
	const float & getY() const;
	const float & getZ() const;
	
	static int getCount();

	~Point3D();
};

#endif	/* POINT_H */
