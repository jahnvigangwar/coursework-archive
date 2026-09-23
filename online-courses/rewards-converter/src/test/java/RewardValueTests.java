import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class RewardValueTests {

    @Test
    void create_with_cash_value() {
        double cashValue = 100;
        var rewardValue = new RewardValue(cashValue);
        assertEquals(cashValue, rewardValue.getCashValue());
    }

    @Test
    void create_with_miles_value() {
        int milesValue = 10000;
        var rewardValue = new RewardValue(milesValue);
        assertEquals(milesValue, rewardValue.getMilesValue());
    }

    @Test
    public void testCashToMilesConversion() {
        //Jahnvi
        // Given a cash value of $100
        double cashValue = 100.0;

        // Create a RewardValue object
        RewardValue rewardValue = new RewardValue(cashValue);

        // Expected miles value should be calculated using the conversion rate (0.0035)
        int expectedMilesValue = (int) (cashValue / 0.0035);

        // Verify that the conversion from cash to miles is accurate
        assertEquals(expectedMilesValue, rewardValue.getMilesValue());
    }

    @Test
    public void testMilesToCashConversion() {
        // Given a miles value of 5000
        int milesValue = 5000;

        // Create a RewardValue object
        RewardValue rewardValue = new RewardValue(milesValue);

        // Expected cash value should be calculated using the conversion rate (0.0035)
        double expectedCashValue = milesValue * 0.0035;

        // Verify that the conversion from miles to cash is accurate
        assertEquals(expectedCashValue, rewardValue.getCashValue(), 0.001); // Using delta for double comparison
    }
}
