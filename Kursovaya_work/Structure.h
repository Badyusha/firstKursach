
// студент
struct Users {
	string login;
	string password;
	string name;

	float averageGrade{};

	float averageEnglish{};
	float averageMath{};
	float averageOaip{};
	float averageOop{};
	float averagePhysics{};

	int group;

	int englishPasses{};
	int mathPasses{};
	int oaipPasses{};
	int oopPasses{};
	int physicsPasses{};

	int mathGradeExam{};
	int englishGradeExam{};
	int oaipGradeExam{};
	int oopGradeExam{};
	int physicsGradeExam{};

	int mathGradeLaba[50]{};
	int englishGradeLaba[50]{};
	int oaipGradeLaba[50]{};
	int oopGradeLaba[50]{};
	int physicsGradeLaba[50]{};

	int mathGradeOlimp{};
	int englishGradeOlimp{};
	int oaipGradeOlimp{};
	int oopGradeOlimp{};
	int physicsGradeOlimp{};

} clients[100];

// препод
struct Professor {
	string login;
	string password;
	string subject;
	string name;
} teachers[100];